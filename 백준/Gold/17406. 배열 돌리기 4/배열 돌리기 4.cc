#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c, s;
int a[101][101], b[101][101], visited[101][101];

int sy, sx, ey, ex, dir;
int ret = INT_MAX;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct rt {
    int y, x, cnt;
};
vector<rt> rt_v;
vector<int> permu;
vector<pair<int, int>> pair_v;

void go(int y, int x, int first) {
    if (!first && y == ey && x == sx) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (visited[ny][nx]) return;
    visited[ny][nx] = 1;
    pair_v.push_back({ny, nx});
    go(ny, nx, 0);
}

void getVertex(int y, int x, int cnt) {
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

        vector<int> one_v;
        for (int j = 0; j < pair_v.size(); j++) {
            one_v.push_back(b[pair_v[j].first][pair_v[j].second]);
        }

        rotate(one_v.begin(), one_v.begin() + one_v.size() - 1, one_v.end());
        for (int j = 0; j < pair_v.size(); j++) {
            b[pair_v[j].first][pair_v[j].second] = one_v[j];
        }
    }
}

int solve() {
    for (int i : permu) {
        getVertex(rt_v[i].y, rt_v[i].x, rt_v[i].cnt);
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += b[i][j];
        }
        ret = min(ret, cnt);
    }
    return ret;
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
        r--;
        c--;
        rt_v.push_back({r, c, s});
        permu.push_back(i);
    }

    do {
        memcpy(b, a, sizeof(b));
        solve();
    } while (next_permutation(permu.begin(), permu.end()));

    cout << ret << '\n';
}