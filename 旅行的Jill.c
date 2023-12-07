#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	FILE* input = fopen("jill.in", "r");
	FILE* output = fopen("jill.out", "w");
	int result_road[100][3];					//  3 �� �ֱ��ʾ������ţ���㣬�յ�
	int length_result = 0;
	int road[100];								// ���·������Ȥ��
	int account, i, h, w;
	fscanf(input, "%d", &account);			       
	while (account) {
		int city_num;
		fscanf(input, "%d", &city_num);
		for (i = 0; i < city_num - 1; i++)
			fscanf(input, "%d", &road[i]);
		int max = 0;							//������������
		int start = 0, end = 0;							//��������յ�
		for (i = 0; i < city_num - 1; i++) {	// ����ÿһ�㶼�����
			if (road[i] < 0)
				continue;
			for (h = city_num - 2; h >= i; h--) {	//����ÿһ�㶼���յ�
				if (road[h] < 0) 
					continue;
				int temp = 0;
				for (w = i; w <= h; w++) 
					temp += road[w];
				if (temp > max) {
					max = temp;
					start = i + 1;
					end = h + 2;
				}
			}
		}
		result_road[length_result][0] = max;
		result_road[length_result][1] = start;
		result_road[length_result++][2] = end;
		account--;
	}
	for (i = 0; i < length_result; i++) {
		if (result_road[i][0] <= 0) {
			fprintf(output, "Route %d has no nice parts\n", i + 1);
		}
		else {
			fprintf(output, "The nicest part of route %d is between stops %d and %d\n", i + 1, result_road[i][1], result_road[i][2]);
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}



