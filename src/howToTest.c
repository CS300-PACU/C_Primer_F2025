/****************************************************************************
 File name:  		howToTest.c
 Author:				chadd williams
 Date:					May 31, 2024
 Class:					CS 300
 Assignment:		C Primer
 Purpose:				Demonstrate C topics: testing
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX INT_MIN
#include <stdbool.h>
#include "../include/howToTest.h"
#include <math.h>

#define SIZE 10
#define LARGE_SIZE 100

 /****************************************************************************
  Function: 	 	findTheMaxInAnArray

  Description: 	This function returns the largest int in an array

  Parameters:		aData - the array
								size - the number of elements in the array

  Returned:	 		integer - the largest value in the array
  ****************************************************************************/
int findTheMaxInAnArray(int aData[], const int size) {
	int max = 0;
	// /nat *(int(*)[10])aData
	for (int i=1; i<size ; ++i){
		if (max < aData[i]) {
			max = aData[i];
		}
	}
	return max;
}

bool circSetRadius(Circle *psCirc, double radius) {
	if (NULL == psCirc) {
		exit(-1);
	}
	if (radius < 0.0) {
		return false;
	}
	psCirc->radius = radius;
	return true;
}

bool circGetRadius(Circle *psCirc, double *pRadius) {
	if (NULL == psCirc || NULL == pRadius) {
		exit(-1);
	}

	*pRadius = psCirc->radius;
	return true;
}

bool circGetArea(Circle *psCirc, double *pArea) {
	if (NULL == psCirc || NULL == pArea) {
		exit(-1);
	}
	if (psCirc->radius < 0) {
		return false;
	}
	*pArea = M_PI * psCirc->radius * psCirc->radius;
	return true;
}