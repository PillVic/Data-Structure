#include"UniverSal.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>


void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//随机数生成器，生成一个i和j之间的一个整数
int RandInt(int i, int j) {
	if (i == j) {
		return i;
	}
	int end = i > j ? i : j;
	int bgn = i + j - end;

	int r = rand();
	r = r % (end - bgn + 1) + bgn;
	return r;
}

