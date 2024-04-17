#include <bits/stdc++.h>
using namespace std;

int x;
int dp[1000001];

void go(int here) {
    if (here == 0) return;
    cout << here << ' ';
    if (here % 3 == 0 && dp[here] == dp[here / 3] + 1)
        go(here / 3);
    else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1)
        go(here / 2);
    else
        go(here - 1);
    return;
}

int main() {
    cin >> x;
    fill(dp, dp + 1000001, 1000004);
    dp[1] = 0;
    for (int i = 1; i <= x; i++) {
        if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    cout << dp[x] << '\n';
    go(x);
    return 0;
}