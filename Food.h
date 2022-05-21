#pragma once
#include"Wall.h"
#include<iostream>

using namespace std;

class Food
{
private:
	int foodX;
	int foodY;
	Wall & m_wall;

public:

	Food(Wall& wall);

	void setFood();

};

