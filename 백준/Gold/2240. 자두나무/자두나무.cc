#include <bits/stdc++.h>
using namespace std;

int t, w, a[1004];
int dp[1001][31][2];

int go(int idx, int cnt, int tree) {
    if (idx == t) return (cnt == 0 ? 0 : -1e9);
    if (cnt < 0) return -1e9;

    int &ret = dp[idx][cnt][tree];
    if (~ret) return ret;

    ret = max(go(idx + 1, cnt, tree), go(idx + 1, cnt - 1, tree ^ 1)) + (tree == a[idx] - 1);
    return ret;
}

int main() {
    cin >> t >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    int ret = 0;
    ret = max(go(0, w, 0), go(0, w - 1, 1));
    cout << ret << '\n';
}