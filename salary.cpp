#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
double aver(double* num,int n) {
	double sum = 0;
	int i;
	for (i = 0; i < n; i++)
		sum += *(num + i);
	return sum / n;
}
int main() {
	int n, i;
	double salary[1000], * p = salary;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lf", (p + i));
	printf("%.2lf", aver(salary, n));
	return 0;
}