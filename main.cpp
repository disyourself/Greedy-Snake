
#include"Wall.h"
#include"Snake.h"
#include"Food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;


static void gotoXY(HANDLE hOut, int x, int y) 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//������ʾ�����



int main() {
	
	//����������
	srand((unsigned int)time(nullptr));

	//�Ƿ������ı�ʶ
	bool isDead = false;

	//��һ���ƶ��ķ���
	char preKey = NULL;


	Wall wall;
	wall.initWall();
	
	Food food(wall);
	Snake snake(wall,food);
	
	

	snake.initSnake();
	food.setFood();

	wall.drawWall();

	while (!isDead)
	{
		//�����û�����
		char key = _getch();

		//����ǵ�һ�ΰ�������Ͳ��ܼ��
		//�������ж���һ���ƶ�����
		if ( key==snake.LEFT&&preKey == NULL) {
			continue;
		}

		do {
			if (key == snake.UP || key == snake.DOWN || 
				key == snake.LEFT || key == snake.RIGHT) 
			{
				//�ж����������� ��ͻ����
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else {
					preKey = key;	//���ǳ�ͻ���������Ը�����
				}


				if (snake.move(key))
				{
					//�ƶ��ɹ�
					//system("cls");
					gotoXY(hOut, 0, 0);

					wall.drawWall();
					wall.wall_socore = snake.getScore();
					//��ȥ��ͷ��λ��
					//gotoXY(hOut,0, 0);

					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					break;
				}
			}
			else
			{
				//�����󰴼���Ϊ��һ�εķ���
				key = preKey;
			}


		} while (!_kbhit());	//��û�м�������ʱ������0	
	}

	system("pause");
	return  1;
}