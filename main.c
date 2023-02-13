#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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

void get_next1_point(double *x, double *y, double yRatio)
{
	*x = *x + 1;
	*y = *y + yRatio;
	printf("checked in 1 x=%f xIndex=%d y=%f yIndex=%d mapValue=%d ", *x, (int)*x, *y, (int)*y, map[(int)*y][(int)*x]);
}

void get_next2_point(double *x, double *y, double xRatio)
{
	*x = *x + xRatio;
	*y = *y + 1;
	printf("checked in 2 x=%f xIndex=%d y=%f yIndex=%d mapValue=%d ", *x, (int)*x, *y, (int)*y, map[(int)*y][(int)*x]);
}

double get_vector_distance(double playerX, double playerY, double angle) {
    double xDiff = cos(angle * ( M_PI / 180));
    double yDiff = sin(angle * (M_PI / 180));
	double xRatio = (1 / yDiff) * xDiff;
	double yRatio = (1 / xDiff) * yDiff;

	//printf("xDiff=%f yDiff=%f\n", xDiff, yDiff);
	//printf("xRatio=%f yRatio=%f\n", xRatio, yRatio);
    double x = playerX;
    double y = playerY;
	double length = 0;

    double x2 = playerX;
    double y2 = playerY;
	double length2 = 0;

	get_next2_point(&x2, &y2, xRatio);
	length2 = sqrt((y2 - playerY) * (y2 - playerY) + (x2 - playerY) * (x2 - playerY));
	printf("length=%f\n", length2);
	if (map[(int)y2][(int)x2] == 1 && x2 >= 0 && x2 < MAP_WIDTH && y2 >= 0 && y2 < MAP_HEIGHT)
	{
		printf("TROUVE 2 final length=%f\n", length2);
		return length2;
	}
	get_next1_point(&x, &y, yRatio);
	length = sqrt((y - playerY) * (y - playerY) + (x - playerY) * (x - playerY));
	printf("length=%f\n", length);
	if (map[(int)y][(int)x] == 1)
	{
		printf("TROUVE 1 final length=%f\n", length);
		return length;
	}
	
    while ((x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT))
    {
		if (length > length2)
		{
			get_next2_point(&x2, &y2, xRatio);
			length2 = sqrt((y2 - playerY) * (y2 - playerY) + (x2 - playerY) * (x2 - playerY));
			printf("length=%f\n", length2);
			if (map[(int)y2][(int)x2] == 1 && x2 >= 0 && x2 < MAP_WIDTH && y2 >= 0 && y2 < MAP_HEIGHT)
			{
				printf("TROUVE 2 final length=%f\n", length2);
				return length2;
			}
		}
		else
		{
			get_next1_point(&x, &y, yRatio);
			length = sqrt((y - playerY) * (y - playerY) + (x - playerY) * (x - playerY));
			printf("length=%f\n", length);
			if (map[(int)y][(int)x] == 1)
			{
				printf("TROUVE 1 final length=%f\n", length);
				return length;
			}
		}
    }
	return 0;
}

int main(void)
{
    double playerX = 5.0;
    double playerY = 5.0;
	double angle = 20;
   
    //for (double angle = 0; angle < 180; angle += 0.1) {
		get_vector_distance(playerX, playerY, angle);
    //}
    return 0;
}