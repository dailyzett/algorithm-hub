#include <bits/stdc++.h>
using namespace std;

int n;
int a[21][21];
int ret = INT_MAX;

// 비트마스킹

int go(vector<int> &v1, vector<int> &v2) {
    pair<int, int> ret;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;
            ret.first += a[v1[i]][v1[j]];
            ret.second += a[v2[i]][v2[j]];
        }
    }
    return abs(ret.first - ret.second);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != n / 2) continue;
        vector<int> start, link;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                start.push_back(j);
            } else {
                link.push_back(j);
            }
        }
        ret = min(ret, go(start, link));
    }
    cout << ret << '\n';
    return 0;
}