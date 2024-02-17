#include <bits/stdc++.h>
using namespace std;

int n, k, l, dir = 1, t, idx;
int a[101][101], visited[101][101];
vector<pair<int, int>> v;
deque<pair<int, int>> dq;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        a[--y][--x] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'L') {
            v.push_back({x, 3});
        } else {
            v.push_back({x, 1});
        }
    }

    dq.push_front({0, 0});
    while (dq.size()) {
        t++;
        int y, x;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;

        if (a[ny][nx]) {  // 사과가 있으면
            a[ny][nx] = 0;
        } else {
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }

        visited[ny][nx] = 1;
        dq.push_front({ny, nx});

        if (t == v[idx].first) {
            dir = (dir + v[idx].second) % 4;
            idx++;
        }
    }

    cout << t << '\n';
    return 0;
}