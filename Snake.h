#pragma once

#include"Wall.h"
#include"Food.h"

class Snake
{
private:
	
	struct Point
	{
		// ˝æ›”Ú
		int x;
		int y;

		//÷∏’Î”Ú
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
};

