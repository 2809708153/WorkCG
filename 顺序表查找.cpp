#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;

typedef struct { 
	ElemType data[MaxSize];
	int length; 
} SqList;

void InitList(SqList &L) {  //初始化顺序表
	//L = (SqList*)malloc(sizeof(SqList));
	L.length = 0;
}
int GetElem(SqList L, int i, ElemType &e) {  //按索引查找
	if (i<1 || i>L.length)
		return 0;
	else {
		e = L.data[i - 1];
		return 1;
	}
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
	PrintElem(L);
	if (GetElem(L, i, e))
		cout << e << endl;
	else {
		cout << L.length << endl;
		cout << "The location does not exist" << endl;
	}
	system("pause");
	return 0;
}
