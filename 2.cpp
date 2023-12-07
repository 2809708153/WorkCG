#include<bits/stdc++.h>
using namespace std;
struct BONE {
	int val;
	int vol;
}bone[1000001];
long long int T, N, V;
long long int dp[1000001];
long long int ans() {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++)
		for (long long int j = V; j >= bone[i].vol; j--)  //反过来循环
			dp[j] = max(dp[j], dp[j - bone[i].vol] + bone[i].val);
	return dp[V];
}
int main() {
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> bone[i].vol;
		cin >> bone[i].val;
	}
	cout << ans() << endl;
	return 0;
}