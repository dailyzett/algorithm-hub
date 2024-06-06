#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 1000001;
const int mod = 1000000000;
int dp[MAX_N];
int main() {
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < MAX_N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }

    int num = abs(n);

    if (n == 0) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    if (n > 0) {
        cout << 1 << '\n';
    } else {
        if (num % 2 == 0) {
            cout << -1 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }

    cout << dp[num] << '\n';
    return 0;
}