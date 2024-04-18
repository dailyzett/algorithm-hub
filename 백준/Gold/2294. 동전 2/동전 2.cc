#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[101];
int dp[10001];
const int INF = 987654321;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(dp, dp + 10001, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }

    if (dp[k] == INF)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
}