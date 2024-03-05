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
void CatList(SqList a, SqList b, SqList& c) {
	int i = 0, j = 0, k = 0;
	while (i < a.length && j < b.length) {
		if (a.data[i] < b.data[j])
			c.data[k++] = a.data[i++];
		else
			c.data[k++] = b.data[j++];
	}
	while (i < a.length)
		c.data[k++] = a.data[i++];
	while (j < b.length)
		c.data[k++] = b.data[j++];
	c.length = k;
}

void PrintElem(SqList L) {  //输出顺序表
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}
int main() {
	int n1, n2, i;
	SqList L1, L2, L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	cin >> n1 >> n2;
	for (i = 0; i < n1; i++) {
		cin >> L1.data[i];
		L1.length++;
	}
	for (i = 0; i < n2; i++) {
		cin >> L2.data[i];
		L2.length++;
	}
	CatList(L1, L2, L3);
	cout << "A:";
	PrintElem(L1);
	cout << "B:";
	PrintElem(L2);
	cout << "C:";
	PrintElem(L3);
	return 0;
}


