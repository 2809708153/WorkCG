#include <iostream>
using namespace std;
#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;

void InitList(SqList& L) {  //��ʼ��˳���
	//L = (SqList*)malloc(sizeof(SqList));
	L.length = 0;
}
void AddList(SqList a, SqList b, SqList& c) {
	int i = 0, j = 0, t, k = 0;
	while (i < a.length) {
		t = a.data[i];
		int flag = 0;
		for (j = 0; j < b.length; j++) {
			if (b.data[j] == t)
				flag = 1;
		}
		if (flag)
			c.data[k++] = t;
		j++;
		i++;
	}
	c.length = k;
}

void PrintElem(SqList L) {  //���˳���
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
	cout << "L1:";
	PrintElem(L1);
	cout << "L2:";
	PrintElem(L2);
	AddList(L1, L2, L3);
	if (L3.length == 0)
		cout << "L3:";
	else {
		cout << "L3:";
		PrintElem(L3);
	}

	return 0;
}
