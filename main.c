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

//int map[MAP_WIDTH][MAP_HEIGHT] = {
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
//};

//double calculateDistance(double playerX, double playerY, double angle) {
//    double xDiff = cos(angle);
//    double yDiff = sin(angle);
//    double x = playerX;
//    double y = playerY;

//    while (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
//    {
//        if (map[(int)x][(int)y] == 1)
//        {
//            printf("wall located at x=%d y=%d\n", (int)x, (int)y);
//            break;
//        }
//        x += xDiff;
//        y += yDiff;
//    }

//    return sqrt((x - playerX) * (x - playerX) + (y - playerY) * (y - playerY));
//}

double test(double playerX, double playerY, double angle) {
    double xDiff = cos(angle * ( M_PI / 180));
    double yDiff = sin(angle * (M_PI / 180));
	double xRatio = (1 / yDiff) * xDiff;
	double yRatio = (1 / xDiff) * yDiff;

    double x = playerX;
    double y = playerY;
	double length = 0;
    while (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
		printf("x=%f xIndex=%d y=%f yIndex=%d mapValue=%d\n", x, (int)x, y, (int)y, map[(int)y][(int)x]);
		if (map[(int)y][(int)x] == 1)
        {
			printf("TROUVE\n");
			break ;
        }
		x = x + 1;
		y = y + yRatio;
    }
	length = sqrt((y - playerY) * (y - playerY) + (x - playerY) * (x - playerY));
	printf("length=%f\n", length);
	return length;
}

int main(void) {
    double playerX = 5.0;
    double playerY = 5.0;
	double angle = 160;
    //double distance = calculateDistance(playerX, playerY, angle);
    //for (double angle = 0; angle < 30; angle += 0.03) {
		test(playerX, playerY, angle);
    //}

    return 0;
}