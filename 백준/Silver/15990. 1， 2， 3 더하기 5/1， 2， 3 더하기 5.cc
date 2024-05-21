#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, dp[100001][4];
ll mod = 1e9 + 9;

int main() {
    for (int i = 1; i <= 100000; i++) {
        if (i - 1 >= 0) {
            dp[i][1] = dp[i - 1][2] + dp[i - 1][3];
            if (i == 1) {
                dp[i][1] = 1;
            }
        }

        if (i - 2 >= 0) {
            dp[i][2] = dp[i - 2][1] + dp[i - 2][3];
            if (i == 2) {
                dp[i][2] = 1;
            }
        }

        if (i - 3 >= 0) {
            dp[i][3] = dp[i - 3][1] + dp[i - 3][2];
            if (i == 3) {
                dp[i][3] = 1;
            }
        }

        dp[i][1] %= mod;
        dp[i][2] %= mod;
        dp[i][3] %= mod;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << '\n';
    }
}