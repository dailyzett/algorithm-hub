#include <bits/stdc++.h>
using namespace std;

int a[100001][3];
int dp[100001][3];
const int INF = 1e9;

int n;

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][1] = a[0][1];
    dp[0][2] = dp[0][1] + a[0][2];
    dp[1][0] = dp[0][1] + a[1][0];
    dp[1][1] = min({dp[1][0], dp[0][1], dp[0][2]}) + a[1][1];
    dp[1][2] = min({dp[0][1], dp[0][2], dp[1][1]}) + a[1][2];

    for (int i = 2; i < n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1]}) + a[i][0];
        dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}) + a[i][1];
        dp[i][2] = min({dp[i - 1][1], dp[i - 1][2], dp[i][1]}) + a[i][2];
    }
}

int main() {
    int k = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }

        solve();
        cout << ++k << ". " << dp[n - 1][1] << '\n';
    }

    return 0;
}