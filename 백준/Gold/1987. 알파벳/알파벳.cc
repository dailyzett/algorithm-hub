#include <bits/stdc++.h>
using namespace std;

int r, c, y, x, ret = INT_MIN;
char a[21][21];
int visited[30];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

        int next = (int)(a[ny][nx] - 'A');
        if (!visited[next]) {
            visited[next] = 1;
            dfs(ny, nx, cnt + 1);
            visited[next] = 0;
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }

    visited[(int)(a[0][0] - 'A')] = 1;
    dfs(0, 0, 1);
    cout << ret << '\n';
}