#pragma once

#include"Wall.h"
#include"Food.h"

class Snake
{
private:
	
	struct Point
	{
		//数据域
		int x;
		int y;

		//指针域
		Point* next;
	};

	Point* pHead;
	Wall& m_wall;
	Food& m_food;
	bool isLoop;

public:

	enum {
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd',
	};



	Snake(Wall& wall,Food&food);

	void initSnake();
	void destoryPoint();	
	void addPoint(int x, int y);
	void deletePoint();

	bool move(char key);

	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取she长度
	int getSankeLenth();

	int getScore();

};

