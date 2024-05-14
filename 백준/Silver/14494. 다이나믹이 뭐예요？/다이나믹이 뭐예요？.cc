#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll dp[1001][1001];
const ll mod = (1e9 + 7);

ll go(int y, int x) {
    if (y == n && x == m) return 1;
    if (y < 0 || x < 0 || y >= n || x >= m) return 0;

    ll &ret = dp[y][x];
    if (ret != -1) return ret;

    ret = 0;
    ret = (ret + go(y + 1, x)) % mod;
    ret = (ret + go(y + 1, x + 1)) % mod;
    ret = (ret + go(y, x + 1)) % mod;

    return ret;
}
int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
    return 0;
}