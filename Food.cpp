#include "Food.h"

Food::Food(Wall& wall):m_wall(wall)
{
	foodX = rand() % (COL - 2) + 1;
	foodY = rand() % (ROW - 2) + 1;
}

void Food::setFood()
{
	while (1)
	{
		foodX = rand() % (COL - 2) + 1;
		foodY = rand() % (ROW - 2) + 1;

		//ʧ�ܵ��ж�
		/*while (m_wall.getWall(foodX, foodY) == '=' || m_wall.getWall(foodX, foodY) == '@')
		{
			foodX = rand() % (COL - 2) + 1;
			foodY = rand() % (ROW - 2) + 1;
		}*/

		//��ȷ���ж�
		if (m_wall.getWall(foodX, foodY) == ' ') 
		{
			m_wall.setWall(foodX, foodY, '$');
			break;
		}
	}
}
