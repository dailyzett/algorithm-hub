#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[251][251];
int visited[251][251];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int sheep, ret_sheep;
int wolf, ret_wolf;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 'v') wolf++;
    if (a[y][x] == 'o') sheep++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (visited[ny][nx] == 1) continue;
        if (a[ny][nx] == '#') continue;
        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '#') continue;
            if (visited[i][j]) continue;
            wolf = 0;
            sheep = 0;
            dfs(i, j);
            if (wolf >= sheep)
                ret_wolf += wolf;
            else
                ret_sheep += sheep;
        }
    }
    cout << ret_sheep << ' ' << ret_wolf;
    return 0;
}