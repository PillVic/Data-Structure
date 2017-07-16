#pragma once

#include<math.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define IsEven(X) !(X&0x1==1)


void swap(int *a, int *b);

int RandInt(int i, int j);

struct Item {
	int Coefficient;
	int Exponent;
};