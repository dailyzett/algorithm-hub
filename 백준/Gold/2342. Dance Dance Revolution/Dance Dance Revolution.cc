#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int dp[5][5][100001];

int check(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;
    return 3;
}

// y - 왼쪽
// x - 오른쪽
int go(int y, int x, int cnt) {
    if (cnt == v.size()) return 0;
    if (dp[y][x][cnt] != -1) return dp[y][x][cnt];

    int left = go(v[cnt], x, cnt + 1) + check(y, v[cnt]);
    int right = go(y, v[cnt], cnt + 1) + check(x, v[cnt]);
    return dp[y][x][cnt] = min(left, right);
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;
        v.push_back(n);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) << '\n';
    return 0;
}