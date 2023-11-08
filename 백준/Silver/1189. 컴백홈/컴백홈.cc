#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int a[12][12], visited[12][12];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret;

int go(int y, int x) {
    if (y == 0 && x == c - 1) {
        if (visited[y][x] == k)
            return 1;
        else
            return 0;
    }

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny >= r || nx >= c || ny < 0 || nx < 0 || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret += go(ny, nx);
        visited[ny][nx] = 0;
    }
    return 0;
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }

    visited[r - 1][0] = 1;
    go(r - 1, 0);
    cout << ret << '\n';
    return 0;
}