#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9)
#define Max 50

typedef struct HT {
	string data;                //节点字符串
	int weight;		            //权重
	int parent, lchild, rchild; //双亲结点和左右孩子节点
}HTNode;



void CreateHT(HTNode* ht, int n) {
	int i, j;
	int lnode, rnode;
	int mi, mipre;   //两最小节点值
	for (i = 0; i < 2 * n - 1; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;  //将所有节点置为-1
	for (i = n; i < 2 * n - 1; i++) {
		mi = mipre = INF;
		lnode = rnode = -1;
		for (j = 0; j <= i - 1; j++)
			if (ht[j].parent == -1) {
				if (ht[j].weight < mi) {
					mipre = mi;
					rnode = lnode;
					mi = ht[j].weight;
					lnode = j;
				}
				else if (ht[j].weight < mipre) {
					mipre = ht[j].weight;
					rnode = j;
				}
			}
		ht[lnode].parent = ht[rnode].parent = i;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
	}
}

//法一，通过寻找当前节点的祖先结点
typedef struct HTC {
	char cd[Max];	             //当前节点哈夫曼码
	int start;	                 //存放起始位置
}HCode;
void CreateHCode(HTNode* ht, HCode *hcd, int n) {
	int i, f, c;
	HCode hc;
	for (i = 0; i < n; i++){
		hc.start = n;
		c = i;
		f = ht[i].parent;
		while (f != -1){    //遍历寻找所有祖先结点
			if (ht[f].lchild == c)
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}
void DispHCode(HTNode *ht, HCode *hcd, int n){
	int i, k, j;
	cout << "data    weight    parent    lchild    rchild" << endl;
	for (i = 0; i < 2 * n - 1; i++) {
		if (i < n)
			cout << setw(8) << ht[i].data << setw(8) << ht[i].weight << setw(10) << ht[i].parent << setw(10) << ht[i].lchild << setw(10) << ht[i].rchild << endl;
		else
			cout << setw(8) << "" << setw(8) << ht[i].weight << setw(10) << ht[i].parent << setw(10) << ht[i].lchild << setw(10) << ht[i].rchild << endl;
	}
	cout << "输出哈夫曼编码:" << endl;
	for (i = 0; i < n; i++){
		j = 0;       
		cout << setw(5) << ht[i].data << ":";
		for (k = hcd[i].start; k <= n; k++){
			cout << hcd[i].cd[k];
			j++;
		}
		cout << endl;
	}
}


//递归求哈夫曼编码
//算法思路，初始字符串为空，从头结点递归遍历到所有叶子节点，对于左子树字符串+='0'，右子树字符串+='1',
//由于最后顺序输出哈夫曼编码，而递归时从左到右所有递归出口利用map哈希表存储，输出时按照顺序输出
void FindHCode(HTNode *ht, int index, string str, int k, map <string,string> &strs) {
	if (k == 0) 
		str += '0';
	else if (k == 1)
		str += '1';
	if (ht[index].lchild == -1 && ht[index].rchild == -1) {
		strs[ht[index].data] = str;
		return;
	}	
	FindHCode(ht, ht[index].lchild, str, 0, strs);
	FindHCode(ht, ht[index].rchild, str, 1, strs);
}
void DispHCode(HTNode* ht, int n, map <string, string> htm) {
	int i;
	cout << "data    weight    parent    lchild    rchild" << endl;
	for (i = 0; i < 2 * n - 1; i++) {
		if (i < n)
			cout << setw(8) << ht[i].data << setw(8) << ht[i].weight << setw(10) << ht[i].parent << setw(10) << ht[i].lchild << setw(10) << ht[i].rchild << endl;
		else
			cout << setw(8) << "" << setw(8) << ht[i].weight << setw(10) << ht[i].parent << setw(10) << ht[i].lchild << setw(10) << ht[i].rchild << endl;
	}
	cout << "输出哈夫曼编码:" << endl;
	for (i = 0; i < n; i++)
		cout << setw(5) << ht[i].data << ":" << htm[ht[i].data] << endl;
}


int main() {
	int n, i, arr[Max];
	string str[Max];
	cin >> n;
	getchar();
	for (i = 0; i < n; i++)
		cin >> str[i];
	for (i = 0; i < n; i++)
		cin >> arr[i];
	HTNode ht[Max];
	for (i = 0; i < n; i++) {
		ht[i].data = str[i];
		ht[i].weight = arr[i];
	}
	CreateHT(ht, n);
	/*
	//法一
	HCode hcd[Max];
	CreateHCode(ht, hcd, n);
	DispHCode(ht, hcd, n);
	*/
	//法二
	map <string, string> res;     //哈希表映射存储
	FindHCode(ht, 2 * n - 2, "", -1, res);  //从根节点(权值最大)空字符串开始递归，根节点无操作即k初始值为-1
	DispHCode(ht, n, res);
	return 0;
}