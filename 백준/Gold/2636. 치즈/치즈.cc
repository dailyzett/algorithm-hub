#include <bits/stdc++.h>
using namespace std;

int n,m,a[102][102], visited[102][102], cnt, cnt2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if(a[y][x] == 1) {
        v.push_back({y, x});
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        else dfs(ny, nx);
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        cnt2 = 0;
        fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
        v.clear();
        dfs(0, 0);
        
        //치즈녹이기
        for(pair<int, int> p: v) {
            cnt2++;
            a[p.first][p.second] = 0;
        }

        //치즈체크
        bool flag = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] != 0) flag = 1;
            }
        }
        cnt++;
        if(!flag) break;
    }
    cout << cnt << '\n' << cnt2 << '\n';
}