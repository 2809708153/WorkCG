#include<iostream>
#include<vector>
using namespace std;

int flag[30][30];

int main(){
	int n, m;
	cin >> n >> m;
	int arr[100][100];
	//vector< vector<int> > arr(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 2; j++){
			if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2]){
				if (flag[i][j] == 0)
					flag[i][j] = 1;
				if (flag[i][j + 1] == 0)
					flag[i][j + 1] = 1;
				if (flag[i][j + 2] == 0)
					flag[i][j + 2] = 1;
			}
		}
	}
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n - 2; i++){
			if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j]){
				if (flag[i][j] == 0)
					flag[i][j] = 1;
				if (flag[i + 1][j] == 0)
					flag[i + 1][j] = 1;
				if (flag[i + 2][j] == 0)
					flag[i + 2][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (flag[i][j] == 1)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}































//以下错误，同一行没有三个及以上，但由于列有导致个数错误
//#include <iostream>
//using namespace std;
//
//const int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };   //DFS数组
//int res[100][100];
//int row, column, C;
////DFS算法
//void paintWithNeighbors(int x, int y, int num){
//    if (x < 0 || x >= row || y < 0 || y >= column || res[x][y] != num)
//        return;
//    C++;
//    res[x][y] = -1;
//    for (int i = 0; i < 4; i++)
//        paintWithNeighbors(x + dir[i][0], y + dir[i][1], num);
//    if (C >= 3)
//        res[x][y] = 0;
//    else
//        res[x][y] = num;
//}
//
//void eliminate(){
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < column; j++)
//            if (res[i][j]) {
//                paintWithNeighbors(i, j, res[i][j]);
//                C = 0;
//            }         
//    }
//}
//
//int main() {
//    cin >> row >> column;
//    for (int i = 0; i < row; i++) 
//        for (int j = 0; j < column; j++) 
//            cin >> res[i][j];
//    eliminate();
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < column; j++) 
//            cout << res[i][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}