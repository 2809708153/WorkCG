#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;

void InitList(SqList& L) {  //初始化顺序表
	//L = (SqList*)malloc(sizeof(SqList));
	L.length = 0;
}
int GetElem(SqList L, int i, ElemType& e) {  //按索引查找
	int j;
	for (j = 0; j < L.length; j++)
		if (L.data[j] == i) {
			e = j + 1;
			return 1;
		}
	return 0;
}
void PrintElem(SqList L) {  //输出顺序表
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}
int main() {
	int n, i, e;
	SqList L;
	InitList(L);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> L.data[i];
		L.length++;
	}
	cin >> i;
	if (GetElem(L, i, e)) {
		PrintElem(L);
		cout << e << endl;
	}
	else {
		cout << "no" << endl;
	}
	system("pause");
	return 0;
}
