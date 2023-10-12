#include <iostream>
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

void PrintElem(SqList L) {  //输出顺序表
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}
int main() {
	int n, i, j;
	SqList L;
	InitList(L);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> L.data[i];
		L.length++;
	}
	int index;
	cin >> index;
	for (i = 0; i < L.length - 1; i++) 
		for (j = i + 1; j < L.length; j++) 
			if (L.data[i] + L.data[j] == index) {
				cout << "yes" << endl;
				return 0;
			}
	cout << "no" << endl;
	return 0;
}
