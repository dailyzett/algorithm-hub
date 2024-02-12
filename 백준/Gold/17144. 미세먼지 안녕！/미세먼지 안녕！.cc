#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int a[54][54], temp[54][54];

int dyDown[] = {0, 1, 0, -1};
int dxDown[] = {1, 0, -1, 0};
int dyUp[] = {0, -1, 0, 1};
int dxUp[] = {1, 0, -1, 0};
vector<pair<int, int>> v1, v2;

void mise(int dy[], int dx[]) {
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != -1 && a[i][j]) {
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int spread = a[y][x] / 5;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= r || ny < 0 || nx >= c || nx < 0 || a[ny][nx] == -1) continue;
            temp[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] += temp[i][j];
        }
    }
    return;
}

vector<pair<int, int>> baramIdx(int sy, int sx, int dy[], int dx[]) {
    vector<pair<int, int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while (true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if (ny == sy && nx == sx) break;
        if (ny >= r || nx >= c || ny < 0 || nx < 0) {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (ny == sy && nx == sx) break;
        y = ny;
        x = nx;
        v.push_back({ny, nx});
    }

    return v;
}

void go(vector<pair<int, int>> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    }
    a[v[0].first][v[0].second] = 0;
    return;
}

int main() {
    cin >> r >> c >> t;
    bool up = true;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];

            if (a[i][j] == -1) {
                if (up) {
                    v1 = baramIdx(i, j, dyUp, dxUp);
                    up = false;
                } else {
                    v2 = baramIdx(i, j, dyDown, dxDown);
                }
            }
        }
    }

    while (t--) {
        mise(dyUp, dxUp);
        go(v1);
        go(v2);
    }

    int ret = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != -1) ret += a[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}