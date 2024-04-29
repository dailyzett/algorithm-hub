#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[101][101];
int visited[101][101];
int ret = 1;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            a[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if (a[ny][nx] == 0) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}