#include <bits/stdc++.h>
using namespace std;

int n, m1, m2, cost;
const int INF = 100004;
int dp[INF];

int main() {
    while (true) {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d.%d", &n, &m1, &m2);
        if (n == 0) break;
        int cost = m1 * 100 + m2;

        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d %d.%d", &k, &m1, &m2);
            int pp = m1 * 100 + m2;
            for (int j = pp; j <= cost; j++) {
                dp[j] = max(dp[j], dp[j - pp] + k);
            }
        }
        cout << dp[cost] << '\n';
    }
    return 0;
}