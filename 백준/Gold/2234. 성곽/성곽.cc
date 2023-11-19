#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[52][52];
int visited[52][52];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int roomCnt;
int roomWidth = INT_MIN;
int roomBroken = INT_MIN;
int roomSize[2502];

int dfs(int y, int x, int cnt) {
    if (visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        if (!(a[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                roomCnt++;
                roomSize[roomCnt] = dfs(i, j, roomCnt);
                roomWidth = max(roomWidth, roomSize[roomCnt]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < m) {
                int firstSize = visited[i + 1][j];
                int secondSize = visited[i][j];
                if (firstSize != secondSize) {
                    roomBroken = max(roomBroken, roomSize[firstSize] + roomSize[secondSize]);
                }
            }

            if (j + 1 < n) {
                int firstSize = visited[i][j + 1];
                int secondSize = visited[i][j];
                if (firstSize != secondSize) {
                    roomBroken = max(roomBroken, roomSize[firstSize] + roomSize[secondSize]);
                }
            }
        }
    }

    cout << roomCnt << '\n';
    cout << roomWidth << '\n';
    cout << roomBroken << '\n';
}