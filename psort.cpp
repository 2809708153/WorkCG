#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <math.h>
void sort(float* arr) {
	int i, j;
	for (i=0;i<9;i++)
		for (j=i+1;j<10;j++)
			if (fabs(arr[i]) < fabs(arr[j])) {
				float t = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = t;
			}
}
int main() {
	float num[10], * p = num;
	int i;
	for (i = 0; i < 10; i++)
		scanf("%f", p + i);
	sort(num);
	for (i = 0; i < 10; i++) {
		printf("%.2f", *(p + i));
		if (i != 9) 
			printf(",");
	}
	return 0;
}