#include <stdio.h>
#include <math.h>

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

double test(double playerX, double playerY, double angle) {
    double xDiff = cos(angle * ( M_PI / 180));
    double yDiff = sin(angle * (M_PI / 180));
	double xRatio = (1 / yDiff) * xDiff;
	double yRatio = (1 / xDiff) * yDiff;

	//yRatio = round(yRatio);
	//printf("xDiff=%f yDiff=%f\n", xDiff, yDiff);
	//printf("xRatio=%f yRatio=%f\n", xRatio, yRatio);
    double x = playerX;
    double y = playerY;
	double length = 0;
    while (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
		//printf("x=%f xIndex=%d y=%f yIndex=%d mapValue=%d\n", x, (int)x, y, (int)y, map[(int)y][(int)x]);
		if (map[(int)y][(int)x] == 1)
        {
			//printf("TROUVE\n");
			break ;
        }
		x = x + 1;
		y = y + yRatio;
    }
	length = sqrt((y - playerY) * (y - playerY) + (x - playerY) * (x - playerY));
	//printf("length=%f\n", length);
	return length;
}

int main(void) {
    double playerX = 5.0;
    double playerY = 5.0;
	double angle = 33;
   
    for (double angle = 0; angle < 180; angle += 0.1) {
		test(playerX, playerY, angle);
    }

    return 0;
}