#include <bits/stdc++.h>
using namespace std;

int n,l,r, a[52][52], visited[52][52], sum, cnt;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>> &v) {
    for(int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        bool openCountry = 0;
        fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 0) {
                    v.clear();
                    visited[i][j] = 1;
                    sum = a[i][j];
                    v.push_back({i, j});
                    dfs(i, j, v);
                    if(v.size() == 1) continue;
                    for(pair<int, int> b: v) {
                        a[b.first][b.second] = sum / v.size();
                        openCountry = 1;
                    }
                }
            }
        }
        if (!openCountry)
            break;
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}