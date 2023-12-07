#include <iostream>
using namespace std;

const int MOD = 10007;

int main() {
    int t;
    cin >> t;
    int arr[10000];
    int r = 0;
    while (t--) {
        int N, K;
        cin >> N >> K;

        int dp[1005] = { 0 };
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= K && j <= i; j++) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        arr[r++] = dp[N];
    }
    for (int i = 0; i < r; i++)
        cout << arr[i] << endl;
    return 0;
}