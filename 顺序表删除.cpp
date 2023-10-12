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
int Deletex(SqList&L, ElemType i,int &e) {  //按索引查找
	if (i<1 || i>L.length)
		return 0;
	int j, k = 0;
	e = L.data[i-1];
	for (j = 0; j < L.length; j++) {
		if (j != i-1) {
			L.data[k] = L.data[j];
			k++;
		}
	}
	L.length = k;
	return 1;
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
	if (Deletex(L, i,e)) {
		PrintElem(L);
		cout << e << endl;
	}
	else {
		cout << "The delete location does not exist" << endl;
		cout << L.length << endl;
	}
		
	system("pause");
	return 0;
}
