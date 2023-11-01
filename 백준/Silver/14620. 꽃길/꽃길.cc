#include <bits/stdc++.h>
using namespace std;

int n;
int a[12][12], visited[12][12];
int ret = INT_MAX;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int addFlower(int y, int x) {
    visited[y][x] = 1;
    int s = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }
    return s;
}

bool isVisible(int y, int x) {
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) return false;
    }
    return true;
}

void plantFlower(int cnt, int totalSum) {
    if (cnt == 3) {
        ret = min(ret, totalSum);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isVisible(i, j)) {
                plantFlower(cnt + 1, totalSum + addFlower(i, j));

                visited[i][j] = 0;
                for (int z1 = 0; z1 < 4; z1++) {
                    int ny = dy[z1] + i;
                    int nx = dx[z1] + j;
                    visited[ny][nx] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    plantFlower(0, 0);
    cout << ret << '\n';
}