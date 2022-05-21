
#include"Wall.h"

using namespace std;



int main() {

	Wall wall;
	wall.initWall();
	


	wall.setWall(5, 4, '=');
	wall.setWall(5, 5, '=');
	wall.setWall(5, 6, '@');

	wall.drawWall();



	system("pause");
	return  1;
}