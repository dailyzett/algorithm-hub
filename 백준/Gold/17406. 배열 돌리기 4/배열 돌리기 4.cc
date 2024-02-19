#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c, s;
int a[101][101], b[101][101], visited[101][101];
int ret = INT_MAX;
int dir = 0;
int sy, sx, ey, ex;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
struct rotate_st {
    int y, x, cnt;
};
vector<rotate_st> v;
vector<int> v_pt;
vector<pair<int, int>> pair_v;  // 2차원 배열을 1차원 배열로 바꾸기 위해 저장하는 vector

bool cmp(rotate_st &a, rotate_st &b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
void go(int y, int x, int first) {
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == ey && x == sx) dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (visited[ny][nx]) return;
    visited[ny][nx] = 1;
    pair_v.push_back({ny, nx});
    go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt) {
    for (int i = 1; i <= cnt; i++) {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;

        pair_v.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        pair_v.push_back({sy, sx});
        go(sy, sx, 1);

        vector<int> one;  // 2차원 -> 1차원을 담는 vector 배열
        for (pair<int, int> p : pair_v) {
            one.push_back(b[p.first][p.second]);
        }
        rotate(one.begin(), one.begin() + one.size() - 1, one.end());
        for (int i = 0; i < pair_v.size(); i++) {
            b[pair_v[i].first][pair_v[i].second] = one[i];
        }
    }
}

int solve() {
    for (int i : v_pt) {
        rotateAll(v[i].y, v[i].x, v[i].cnt);
    }
    int _ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += b[i][j];
        }
        _ret = min(_ret, cnt);
    }
    return _ret;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        --r;
        --c;
        v.push_back({r, c, s});
        v_pt.push_back(i);
    }

    do {
        memcpy(b, a, sizeof(b));
        ret = min(ret, solve());
    } while (next_permutation(v_pt.begin(), v_pt.end()));

    cout << ret << '\n';

    return 0;
}