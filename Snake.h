#pragma once

#include"Wall.h"
#include"Food.h"

class Snake
{
private:
	
	struct Point
	{
		//������
		int x;
		int y;

		//ָ����
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

	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡshe����
	int getSankeLenth();

	int getScore();

};

