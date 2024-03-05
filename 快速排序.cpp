#include <bits/stdc++.h>
using namespace std;

//递归输出数组
void Print(int* arr, int i, int n) {
	if (i < n) {
		cout << arr[i] << " ";
		Print(arr, i + 1, n);
	}
}
//快速排序
void QuickSort(int* arr, int s, int t, int len, int& count) {
	int i = s, j = t, temp;
	if (s < t) {
		temp = arr[s];
		while (i != j) {
			while (j > i && arr[j] >= temp)
				j--;
			arr[i] = arr[j];
			while (i < j && arr[i] <= temp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = temp;
		Print(arr, 0, len);
		count++;
		cout << endl;
		QuickSort(arr, s, i - 1, len, count);
		QuickSort(arr, i + 1, t, len, count);
	}
}

int main() {
	int num[1001], x, i = 0, count = 0;
	while (1) {
		cin >> x;
		if (x == -1)
			break;
		num[i++] = x;
	}
	cout << "排序前:";
	Print(num, 0, i);
	cout << endl;
	QuickSort(num, 0, i - 1, i, count);
	cout << "排序后:";
	Print(num, 0, i);
	cout << endl;
	cout << "count=" << count << endl;
	system("pause");
	return 0;
}