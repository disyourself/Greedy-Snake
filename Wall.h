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
	void setWall(int x, int y, char c); //根据索引设置二维数组里的内容
	char getWall(int x,int y);	//获取当前位置的符号
	
private:

	char gameArray[ROW][COL];

};



#endif // !WALL_H


