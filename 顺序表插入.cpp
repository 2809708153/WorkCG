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
int InsElem(SqList& L, int i, int e) {   //按索引插入
	if (i<1 || i>L.length)
		return 0;
	int j;
	for (j = L.length; j > i - 1; j--) 
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
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
	cin >> e;
	if (InsElem(L, i, e)) {
		PrintElem(L);
	}
	else {
		cout << "The insertion position does not exist" << endl;
		cout << L.length << endl;
	}
	system("pause");
	return 0;
}
