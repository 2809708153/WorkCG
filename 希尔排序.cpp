#include <bits/stdc++.h>
using namespace std;

//µİ¹éÊä³öÊı×é
void Print(int* arr, int i, int n) {
	if (i < n) {
		cout << setw(4) << arr[i];
		Print(arr, i + 1, n);
	}
}
//Ï£¶ûÅÅĞò
void ShellSort(int* arr, int len, int* dist, int len2) {
	int i, j, d, temp, k = 0;
	d = dist[k++];
	while (k <= len2) {
		for (i = d; i < len; i++) {
			temp = arr[i];
			j = i - d;
			while (j >= 0 && temp < arr[j]) {
				arr[j + d] = arr[j];
				j -= d;
			}
			arr[j + d] = temp;
		}
		d = dist[k++];
		Print(arr, 0, len);
		cout << endl;
	}
}


int main() {
	int num[1001], x, i;
	int n, dist[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> dist[i];
	i = 0;
	while (1) {
		cin >> x;
		if (x == -1)
			break;
		num[i++] = x;
	}
	cout << "the resource datas is:" << endl;
	Print(num, 0, i);
	cout << endl;
	cout << "every shellinsert px result is" << endl;
	ShellSort(num, i, dist, n);
	cout << "the shellinsert result datas is:" << endl;
	Print(num, 0, i);
	cout << endl;
	system("pause");
	return 0;
}