#include <bits/stdc++.h>
using namespace std;

int n;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[12][12], visited[12][12];
int ret = INT_MAX;

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

int caculateFlower(int y, int x) {
    visited[y][x] = 1;
    int s = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }
    return s;
}

bool isVisited(int y, int x) {
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false;
    }
    return true;
}

void plant(int cnt, int flowerSum) {
    if (cnt == 3) {
        ret = min(ret, flowerSum);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isVisited(i, j)) {
                plant(cnt + 1, flowerSum + caculateFlower(i, j));
                eraseFlower(i, j);
            } else {
                continue;
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

    plant(0, 0);
    cout << ret << '\n';
}