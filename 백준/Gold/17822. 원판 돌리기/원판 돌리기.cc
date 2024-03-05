#include <bits/stdc++.h>
using namespace std;

int a[52][52];
int visited[52][52];
int n, m, t;
int x, d, k;
int ret, flag = 1;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void rotate2(int y, int dir, int k) {
    vector<int> v;
    for (int i = 0; i < m; i++) {
        v.push_back(a[y][i]);
    }
    if (dir == 1)
        rotate(v.begin(), v.begin() + k, v.end());
    else
        rotate(v.begin(), v.begin() + m - k, v.end());
    for (int i = 0; i < m; i++) a[y][i] = v[i];
    return;
}

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;

        if (ny < 0 || ny >= n) continue;
        if (visited[ny][nx]) continue;
        if (a[y][x] == a[ny][nx]) {
            visited[y][x] = visited[ny][nx] = 1;
            flag = 0;
            dfs(ny, nx);
        }
    }
}

void getAverage() {
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            sum += a[i][j];
            cnt++;
        }
    }
    double av = (double)sum / (double)cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            if ((double)a[i][j] > av)
                a[i][j]--;
            else if ((double)a[i][j] < av)
                a[i][j]++;
        }
    }
    return;
}

bool findAdj() {
    flag = 1;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            if (visited[i][j]) continue;
            dfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) a[i][j] = 0;
        }
    }
    return flag;
}

int main() {
    // 1. 원판을 입력받는다.
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int z = 0; z < t; z++) {
        cin >> x >> d >> k;

        for (int j = x - 1; j < n; j += x) {
            rotate2(j, d, k);
        }
        if (findAdj()) getAverage();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }
    }
    cout << ret << '\n';
}