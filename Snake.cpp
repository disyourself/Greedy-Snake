#include "Snake.h"

Snake::Snake(Wall& wall,Food&food) :m_wall(wall),m_food(food)
{
	pHead = nullptr;
	isLoop = false;
}

void Snake::initSnake()
{
	destoryPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}


//�������нڵ�
void Snake::destoryPoint()
{
	Point* pCur = pHead;
	while (pHead!=nullptr)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int inx, int iny) 
{
	Point* newPoint = new Point;
	newPoint->x = inx;
	newPoint->y = iny;
	newPoint->next = nullptr;

	//���ԭ����ͷ��Ϊ�գ���Ϊ����
	if (pHead) 
	{
		m_wall.setWall(pHead->x, pHead->y, '=');
	}

	//����ͷ��
	newPoint->next = pHead;
	pHead = newPoint;
	m_wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::deletePoint()
{
	if (!pHead || !pHead->next) return;

	Point* cur = pHead->next, * pre = pHead;

	while (cur->next)
	{
		cur = cur->next;
		pre = pre->next;
	}
	m_wall.setWall(cur->x, cur->y, ' ');
	delete cur;
	cur = nullptr;
	pre->next = nullptr;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;


	switch (key)
	{
	case UP:x--;
		break;
	case DOWN:x++;
		break;
	case LEFT:y--;
		break;
	case RIGHT:y++;
		break;
	}
	
	//�����һ����������β�ͣ���Ӧ������
	Point* cur = pHead->next, * pre = pHead;
	while (cur->next)
	{
		cur = cur->next;
		pre = pre->next;
	}
	if (cur->x == x && cur->y == y)
	{
		//����β�� ѭ��
		isLoop = true;
	}
	else
	{
		//�ж��û�����λ���Ƿ�ɹ�
		if (m_wall.getWall(x, y) == '*' || m_wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			system("cls");
			m_wall.drawWall();
			cout << "GAME OVER!!!!" << endl;
			return false;
		}
	}

	//�ƶ��ɹ�������
	if (m_wall.getWall(x, y) == '$') 
	{
		// 1. �Ե�ʳ��
		addPoint(x, y);
		m_food.setFood();
	}
	else {
		int ix = x;
		int iy = y;

		if (isLoop == true) {
			m_wall.setWall(ix, iy, '@');
		}


		// 2. û�Ե�ʳ��
		addPoint(ix, iy);
		deletePoint();
	}

	isLoop = false;
	return true;
}
