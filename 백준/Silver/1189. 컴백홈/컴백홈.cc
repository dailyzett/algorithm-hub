#include <bits/stdc++.h>
using namespace std;

int y, x, k;
string s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[10][10];
char a[10][10];

int go(int paramY, int paramX) {
    if (paramY == 0 && paramX == x - 1) {
        if (visited[paramY][paramX] == k) return 1;
        return 0;
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + paramY;
        int nx = dx[i] + paramX;
        if (ny >= y || ny < 0 || nx >= x || nx < 0 || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[paramY][paramX] + 1;
        ret += go(ny, nx);
        visited[ny][nx] = 0;
    }
    return ret;
}

int main() {
    cin >> y >> x >> k;
    for (int i = 0; i < y; i++) {
        cin >> s;
        for (int j = 0; j < x; j++) {
            a[i][j] = s[j];
        }
    }
    visited[y - 1][0] = 1;
    cout << go(y - 1, 0) << '\n';

    return 0;
}