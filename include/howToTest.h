/****************************************************************************
 File name:  		howToTest.h
 Author:				chadd williams
 Date:					May 31, 2024
 Class:					CS 300
 Assignment:		C Primer
 Purpose:				Demonstrate C topics: testing
 ****************************************************************************/

#include <math.h>

int findTheMaxInAnArray(int aData[], const int size);

typedef struct Circle {
	double radius;
	int x, y;
} Circle;

bool circSetRadius(Circle *psCirc, double radius);
bool circGetRadius(Circle *psCirc, double *pRadius);
bool circGetArea(Circle *psCirc, double *pArea);