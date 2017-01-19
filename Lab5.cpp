// Ћаб5языкиѕрограммировани€.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <cctype> // дл€ функции isalnum
#include <cstdlib> // содержит srand() и rand()
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	int x1 = 4; //strip from smalest coordinates of the dot 
	int x2 = 8;
	int y1 = 5;
	int y2 = 8;

	int a1 = 2; //ray
	int a2 = 8;
	int b1 = 8;
	int b2 = 5;

	float X;
	float Y;

	Y = (((x1*y2 - x2*y1)*(b1 - b2)) / (y1 - y2) + (a2*b1 - a1*b2)) / ((a2 - a1) - ((x2 - x1)*(b1 - b2)) / (y1 - y2));
	
	X = -((x2 - x1)*Y + (x1*y2 - x2*y1)) / (y1 - y2);

	printf("Dot of crossing:  X = %f,  Y = %f    \n", X, Y);

	float K1 = (y1 - y2)*X + (x2 - x1)*Y + (x1*y2 - x2*y1);
	float K2 = (b1 - b2)*X + (a2 - a1)*Y + (a1*b2 - a2*b1);

	//printf("K1 = %f,  K2 = %f    \n", K1, K2);

	bool b = false;

	if (((K1) == 0) & (X >= x1) & (X <= x2) & (Y >= y1) & (Y <= y2)) { //belongs to the strip
		printf("Yes\n");
		if (((K2) == 0)) { //belongs to the ray
			printf("Yes2\n");
			if (a1 < a2) {
				if (b1 < b2) {
					if ((X >= a1) & (Y >= b1)) {
						printf("Yes2\n"); // dot of crossing
						b = 1;
					}
				}
				else if (b1 > b2) {
					if ((X >= a1) & (Y <= b2)) {
						printf("Yes2\n");	// dot of crossing
						b = 1;
					}
				}
			}
			else {
				if (a1 > a2) {
					if (b1 < b2) {
						if ((X <= a2) & (Y <= b2)) {
							printf("Yes2\n");	// dot of crossing
							b = 1;
						}
					}
					else if (b1 > b2) {
						if ((X <= a2) & (Y >= b1)) {
							printf("Yes2\n");	// dot of crossing
							b = 1;
						}
					}
				}
			}
		}
	}
	
	if (b == 0){
		printf("No\n");
	}


    return 0;
}

