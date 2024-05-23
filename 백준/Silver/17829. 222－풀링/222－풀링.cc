#include <bits/stdc++.h>
using namespace std;

int n, a[1025][1025];

int go(int idx, int y, int x) {
    if (idx == 1) return a[y][x];

    vector<int> v;
    for (int i = y; i < idx + y; i += idx / 2) {
        for (int j = x; j < idx + x; j += idx / 2) {
            v.push_back(go(idx / 2, i, j));
        }
    }

    sort(v.begin(), v.end());
    return v[2];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << go(n, 0, 0) << '\n';
    return 0;
}