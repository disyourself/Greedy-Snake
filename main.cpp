
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
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//定义显示器句柄



int main() {
	
	//添加随机种子
	srand((unsigned int)time(nullptr));

	//是否死亡的标识
	bool isDead = false;

	//上一次移动的方向
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
		//接收用户输入
		char key = _getch();

		//如果是第一次按的左键就不能激活，
		//启动后判断上一次移动方向
		if ( key==snake.LEFT&&preKey == NULL) {
			continue;
		}

		do {
			if (key == snake.UP || key == snake.DOWN || 
				key == snake.LEFT || key == snake.RIGHT) 
			{
				//判断左右与上下 冲突按键
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else {
					preKey = key;	//不是冲突按键，可以更新了
				}


				if (snake.move(key))
				{
					//移动成功
					//system("cls");
					gotoXY(hOut, 0, 0);

					wall.drawWall();
					wall.wall_socore = snake.getScore();
					//回去找头的位置
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
				//将错误按键变为上一次的方向
				key = preKey;
			}


		} while (!_kbhit());	//当没有键盘输入时，返回0	
	}

	system("pause");
	return  1;
}