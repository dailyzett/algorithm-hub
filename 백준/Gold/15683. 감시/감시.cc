#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[9][9];
int ret = INT_MAX;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> camera;

vector<pair<int, int>> cctv(int here, int dir) {
    vector<pair<int, int>> change_cctv;
    int y = camera[here].first;
    int x = camera[here].second;
    if (a[y][x] == 1) {
        while (true) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 100;
                    change_cctv.push_back({ny, nx});
                }
                y = ny;
                x = nx;
            } else
                break;
        }
    } else if (a[y][x] == 2) {
        for (int i = 0; i <= 2; i += 2) {
            int cy = y;
            int cx = x;
            while (true) {
                int ny = cy + dy[(dir + i) % 4];
                int nx = cx + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 100;
                        change_cctv.push_back({ny, nx});
                    }
                    cy = ny;
                    cx = nx;
                } else
                    break;
            }
        }
    } else if (a[y][x] == 3) {
        for (int i = 0; i < 2; i++) {
            int cy = y;
            int cx = x;
            while (true) {
                int ny = cy + dy[(dir + i) % 4];
                int nx = cx + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 100;
                        change_cctv.push_back({ny, nx});
                    }
                    cy = ny;
                    cx = nx;
                } else
                    break;
            }
        }
    } else if (a[y][x] == 4) {
        for (int i = 0; i < 3; i++) {
            int cy = y;
            int cx = x;
            while (true) {
                int ny = cy + dy[(dir + i) % 4];
                int nx = cx + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 100;
                        change_cctv.push_back({ny, nx});
                    }
                    cy = ny;
                    cx = nx;
                } else
                    break;
            }
        }
    } else if (a[y][x] == 5) {
        for (int i = 0; i < 4; i++) {
            int cy = y;
            int cx = x;
            while (true) {
                int ny = cy + dy[(dir + i) % 4];
                int nx = cx + dx[(dir + i) % 4];
                if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6) {
                    if (a[ny][nx] == 0) {
                        a[ny][nx] = 100;
                        change_cctv.push_back({ny, nx});
                    }
                    cy = ny;
                    cx = nx;
                } else
                    break;
            }
        }
    }
    return change_cctv;
}

void go(int here) {
    if (here == camera.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) cnt++;
            }
        }
        ret = min(ret, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> temp = cctv(here, i);
        go(here + 1);
        for (auto p : temp) {
            a[p.first][p.second] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            a[i][j] = num;
            if (num != 0 && num != 6) {
                camera.push_back({i, j});
            }
        }
    }

    go(0);
    cout << ret << '\n';
    return 0;
}