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


//销毁所有节点
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

	//如果原来的头不为空，改为身子
	if (pHead) 
	{
		m_wall.setWall(pHead->x, pHead->y, '=');
	}

	//更新头部
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
	
	//如果下一步碰到的是尾巴，不应该死亡
	Point* cur = pHead->next, * pre = pHead;
	while (cur->next)
	{
		cur = cur->next;
		pre = pre->next;
	}
	if (cur->x == x && cur->y == y)
	{
		//碰到尾巴 循环
		isLoop = true;
	}
	else
	{
		//判断用户到达位置是否成功
		if (m_wall.getWall(x, y) == '*' || m_wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			system("cls");
			m_wall.drawWall();
			cout << "GAME OVER!!!!" << endl;
			return false;
		}
	}

	//移动成功分两种
	if (m_wall.getWall(x, y) == '$') 
	{
		// 1. 吃到食物
		addPoint(x, y);
		m_food.setFood();
	}
	else {
		int ix = x;
		int iy = y;

		if (isLoop == true) {
			m_wall.setWall(ix, iy, '@');
		}


		// 2. 没吃到食物
		addPoint(ix, iy);
		deletePoint();
	}

	isLoop = false;
	return true;
}
