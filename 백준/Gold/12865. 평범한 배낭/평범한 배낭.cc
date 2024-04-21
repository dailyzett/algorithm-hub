#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100003;
int n, k, w, v;
int dp[MAX_V];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;

        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[k] << '\n';
    return 0;
}