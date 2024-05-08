#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int a[14];
int dp[11][21][1 << 14];

int go(int idx, int capacity, int bosuk) {
    if (idx == m) return 0;

    int &ret = dp[idx][capacity][bosuk];
    if (ret) return ret;

    ret = max(ret, go(idx + 1, c, bosuk));
    for (int i = 0; i < n; i++) {
        bool isHasBosuk = (1 << i) & bosuk;
        bool isPushBosuk = (capacity - a[i]) >= 0;
        if (!isHasBosuk && isPushBosuk) {
            ret = max(ret, go(idx, capacity - a[i], bosuk | (1 << i)) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(0, c, 0);
    return 0;
}