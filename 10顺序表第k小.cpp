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
void FList(SqList a, SqList b,int k,int &res) {
	int i = 0, j = 0;
	if (k > a.length + b.length)
		return;
	while (i < a.length && j < b.length && k>0) {
		if (a.data[i] < b.data[j]) {
			res = a.data[i];
			i++;
		}
		else {
			res = b.data[j];
			j++;
		}	
		k--;
	}
	while (i < a.length && k>0) {
		res = a.data[i];
		i++;
		k--;
	}	
	while (j < b.length && k>0) {
		res = b.data[j];
		j++;
		k--;
	}
}

void PrintElem(SqList L) {  //输出顺序表
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}
int main() {
	int n1, n2, i, k;
	SqList L1, L2;
	InitList(L1);
	InitList(L2);
	cin >> n1 >> n2 >> k;
	for (i = 0; i < n1; i++) {
		cin >> L1.data[i];
		L1.length++;
	}
	for (i = 0; i < n2; i++) {
		cin >> L2.data[i];
		L2.length++;
	}
	int res = -1;
	FList(L1, L2,k, res);
	cout << "L1:";
	PrintElem(L1);
	cout << "L2:";
	PrintElem(L2);
	if (res != -1)
		cout << "The " << k << " smallest element:" << res;
	else
		cout << "k=" << k << ":Parameter error";
	return 0;
}


