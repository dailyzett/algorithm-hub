#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2005];
int dp[2005][2005];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

bool isPal(int s, int e) {
    for (int i = 0; i <= (e - s) / 2; i++) {
        if (a[s + i] != a[e - i]) return false;
    }
    return true;
}

int main() {
    fastIO();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
    }

    for (int numSize = 2; numSize <= n; numSize++) {
        for (int i = 1; i <= n - numSize; i++) {
            if (a[i] == a[i + numSize] && dp[i + 1][i + numSize - 1]) dp[i][i + numSize] = 1;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}