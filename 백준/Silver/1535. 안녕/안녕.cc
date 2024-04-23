#include <bits/stdc++.h>
using namespace std;

int n;
int a[21], b[21], dp[101];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 100; j > a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[100] << '\n';
}