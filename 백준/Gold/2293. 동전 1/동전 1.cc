#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[101];
int dp[10001];
int main() {
    cin >> n >> k;
    if (n > 100) exit(0);
    if (k >= 10001) exit(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[k] << '\n';
    return 0;
}