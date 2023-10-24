#include <bits/stdc++.h>
using namespace std;

/**
 * 0: 빈공간
 * 1: 친ㅜ
 * *: 주난
 * #: 범인
 */
const int MAX = 302;
int n, m, jx, jy, tx, ty, x, y, level;
char a[MAX][MAX];
string s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[MAX][MAX];

int main() {
    cin >> n >> m;
    cin >> jy >> jx >> ty >> tx;
    jy--;
    jx--;
    ty--;
    tx--;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    queue<pair<int, int>> q;
    q.push({jy, jx});
    visited[jy][jx] = 1;

    while (true) {
        level++;
        queue<pair<int, int>> temp;

        while (q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = level;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
            }
        }
        q = temp;

        if (a[ty][tx] == '0') break;
    }

    cout << visited[ty][tx] << '\n';
    return 0;
}