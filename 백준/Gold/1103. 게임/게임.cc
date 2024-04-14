#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];
int dp[51][51];
bool visited[51][51];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

bool check(int y, int x) {
    if (y >= 1 && y <= n && x >= 1 && x <= m)
        return true;
    else
        return false;
}

int go(int y, int x) {
    if (!check(y, x) || a[y][x] == 24) return 0;
    if (visited[y][x]) {
        cout << -1 << '\n';
        exit(0);
    }

    int &ret = dp[y][x];
    if (ret) return ret;

    visited[y][x] = 1;
    int value = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, go(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    cout << go(1, 1) << '\n';
}