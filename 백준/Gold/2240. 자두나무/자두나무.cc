#include <bits/stdc++.h>
using namespace std;

int t, w;
int jadu[1001];
int dp[1001][2][31];

int go(int idx, int tree, int cnt) {
    if (idx == t) return 0;
    if (cnt < 0) return -1e9;

    int &ret = dp[idx][tree][cnt];
    if (~ret) return ret;

    ret = max(go(idx + 1, tree, cnt), go(idx + 1, tree ^ 1, cnt - 1)) + (tree == jadu[idx] - 1);
    return ret;
}

int main() {
    cin >> t >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < t; i++) {
        cin >> jadu[i];
    }

    int ret = max(go(0, 0, w), go(0, 1, w - 1));
    cout << ret << '\n';
    return 0;
}