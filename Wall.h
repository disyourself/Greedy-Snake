#ifndef WALL_H
#define WALL_H

#include<iostream>
using namespace std;

enum {
	ROW = 26,
	COL = 30,
};

class Wall
{
public:

	void initWall();
	void drawWall();
	void setWall(int x, int y, char c); //�����������ö�ά�����������
	char getWall(int x,int y);	//��ȡ��ǰλ�õķ���
	int wall_socore=0;
	

private:

	char gameArray[ROW][COL];

	
};



#endif // !WALL_H


