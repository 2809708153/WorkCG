#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 32767

//迪杰斯特拉算法
void Dijkstra(int n, int v, int(*Edges)[100], int* dist, int* path) {
	int visited[MAX] = { 0 };    //建立"S"数组
	dist[v] = 0;
	for (int i = 0; i < n; i++) {
		int minDist = INF;
		int u = 0;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && dist[j] < minDist) {
				minDist = dist[j];
				u = j;
			}
		}
		visited[u] = 1;
		for (int k = 0; k < n; k++) {
			if (!visited[k] && Edges[u][k] != INF && dist[u] + Edges[u][k] < dist[k]) {
				dist[k] = dist[u] + Edges[u][k];
				path[k] = u;
			}
		}
	}
}
//反向输出path数组即路径（递归实现）
void printPath(int* path, int v, int u, int k) {    //定义变量k防止最后多输出一个逗号
	if (path[u] != -1 && v != u)
		printPath(path, v, path[u], k + 1);
	cout << u;
	if (k != 0)
		cout << ",";
}

int main() {
	int n, v;
	cout << "输入顶点数：" << endl;
	cin >> n;
	int Edges[MAX][MAX];
	cout << "输入有向网的信息：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Edges[i][j];
			if (Edges[i][j] == 0)  //处理对角线
				Edges[i][j] = INF;
		}
	}
	cout << "输入出发顶点：" << endl;
	cin >> v;
	int dist[MAX], path[MAX];
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		path[i] = -1;
	}
	Dijkstra(n, v, Edges, dist, path);
	cout << "从" << v << "顶点出发的最短路径如下:" << endl;
	for (int i = 0; i < n; i++) {
		if (i == v || dist[i] == INF)
			continue;
		cout << "  从顶点" << v << "到顶点" << i << "的路径长度为:" <<  dist[i] << "\t" << "路径为:";
		printPath(path, v, i, 0);
		cout << endl;
	}
	system("pause");
	return 0;
}






