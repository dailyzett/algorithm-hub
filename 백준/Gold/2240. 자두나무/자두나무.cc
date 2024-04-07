#include <bits/stdc++.h>
using namespace std;

int t, w;
int dp[1004][31][2];
int a[1004];

// t -> idx
// w -> cnt
int go(int idx, int cnt, int tree) {
    // 기저사례
    if (cnt < 0) return -1e9;
    if (t == idx) return cnt == 0 ? 0 : -1e9;

    // 메모이제이션
    int &ret = dp[idx][cnt][tree];
    if (~ret) return ret;

    // 로직
    ret = max(go(idx + 1, cnt - 1, tree ^ 1), go(idx + 1, cnt, tree)) + (tree == a[idx] - 1);
    return ret;
}

int main() {
    cin >> t >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }
    int ret = max(go(0, w, 0), go(0, w - 1, 1));
    cout << ret << '\n';

    return 0;
}