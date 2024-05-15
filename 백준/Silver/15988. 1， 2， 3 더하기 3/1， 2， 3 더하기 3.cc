#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000009;
const int MAX = 1000001;
ll dp[MAX];
int t;
int main() {
    cin >> t;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }

    while (t--) {
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
}