#include <bits/stdc++.h>
using namespace std;

int n, c, ret;
int a[31];
vector<int> v1, v2;

// 가방 무게를 합산한 v1, v2
void go(int here, int mx, vector<int> &v, int sum) {
    if (sum > c) return;
    if (here > mx) {
        v.push_back(sum);
        return;
    }

    go(here + 1, mx, v, sum + a[here]);
    go(here + 1, mx, v, sum);
    return;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    go(0, n / 2 - 1, v1, 0);
    go(n / 2, n - 1, v2, 0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int v : v1) {
        if (c - v >= 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), c - v) - v2.begin()));
    }
    cout << ret << '\n';
    return 0;
}