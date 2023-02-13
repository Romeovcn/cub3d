#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

int map[10][10] = {
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

void get_next1_point(double *x, double *y, double yRatio, int quartile)
{
	if (quartile == 1 || quartile == 4)
		*x = *x + 1;
	else
		*x = *x - 1;

	if (quartile == 1 || quartile == 4)
		*y = *y + yRatio;
	else if (quartile == 2)
		*y = *y + (yRatio * -1);
	else
		*y = *y - yRatio;
	printf("checked in 2 x=%f y=%f xIndex=%d yIndex=%d mapValue=%d ", *x, *y, (int)*x, (int)*y, map[(int)*y][(int)*x]);
}

void get_next2_point(double *x, double *y, double xRatio, int quartile)
{
	if (quartile == 1 || quartile == 4)
		*x = *x + xRatio;
	else
		*x = *x - xRatio;
	if (quartile == 1 || quartile == 2)
		*y = *y + 1;
	else
		*y = *y - 1;
	printf("checked in 2 x=%f y=%f xIndex=%d yIndex=%d mapValue=%d ", *x, *y, (int)*x, (int)*y, map[(int)*y][(int)*x]);
}

double get_vector_distance(double playerX, double playerY, double angle) {
    double xDiff = cos(angle * ( M_PI / 180));
    double yDiff = sin(angle * (M_PI / 180));
	double xRatio = (1 / yDiff) * xDiff;
	double yRatio = (1 / xDiff) * yDiff;

	// printf("xDiff=%f yDiff=%f\n", xDiff, yDiff);
	// printf("xRatio=%f yRatio=%f\n", xRatio, yRatio);
    double x = playerX;
    double y = playerY;
	double length = 0;

    double x2 = playerX;
    double y2 = playerY;
	int quartile;

	double length2 = 0.1;
	if (angle >= 0 && angle <= 90)
	{
		printf("%f bas droite x++ y++\n", angle);
		quartile = 1;
	}
	else if (angle >= 91 && angle <= 180)
	{
		printf("%f bas gauche x-- y++\n", angle);
		quartile = 2;
	}
	else if (angle >= 181 && angle <= 270)
	{
		printf("%f haut gauche x-- y--\n", angle);
		quartile = 3;
	}
	else if (angle >= 271 && angle <= 360)
	{
		printf("%f haut droite x++ y--\n", angle);
		quartile = 4;
	}
    while (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
		// if (length > length2)
		// {
		// 	get_next2_point(&x2, &y2, xRatio, quartile);
		// 	length2 = sqrt((y2 - playerY) * (y2 - playerY) + (x2 - playerY) * (x2 - playerY));
		// 	printf("length=%f\n", length2);
		// 	if (map[(int)y2][(int)x2] == 1 && x2 >= 0 && x2 < MAP_WIDTH && y2 >= 0 && y2 < MAP_HEIGHT)
		// 	{
		// 		printf("-------------------\nTROUVE 2 final length=%f at %f, %f\n", length2, x2, y2);
		// 		return length2;
		// 	}
		// }
		// else
		// {
			get_next1_point(&x, &y, yRatio, quartile);
			length = sqrt((y - playerY) * (y - playerY) + (x - playerY) * (x - playerY));
			printf("length=%f\n", length);
			if (quartile == 1 && map[(int)y][(int)x] == 1)
			{
				printf("-------------------\nTROUVE 1 final length=%f at %f, %f\n", length, x, y);
				return length;
			}
			else if (quartile == 2 && map[(int)y][(int)x - 1] == 1)
			{
				printf("-------------------\nTROUVE 1 final length=%f at %f, %f\n", length, x, y);
				return length;
			}
			else if (quartile == 3 && map[(int)y][(int)x - 1] == 1)
			{
				printf("-------------------\nTROUVE 1 final length=%f at %f, %f\n", length, x, y);
				return length;
			}
			else if (quartile == 4 && map[(int)y][(int)x] == 1)
			{
				printf("-------------------\nTROUVE 1 final length=%f at %f, %f\n", length, x, y);
				return length;
			}
		// }
    }
	return 0;
}

int main(void)
{
    double playerX = 5.0;
    double playerY = 5.0;
	double angle = 212.5;
   
    // for (double angle = 0; angle < 361; angle += 1) {
		get_vector_distance(playerX, playerY, angle);
    // }
    return 0;
}