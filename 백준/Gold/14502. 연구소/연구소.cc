#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 벽을 세개 세운다. (모든 경우의 수 - 브루트 포스)
 * 2. 바이러스를 퍼뜨린다. (DFS)
 * 3. 안전 영역을 카운팅해서 MAX 값을 리턴한다.
*/

int n, m, a[10][10], visited[10][10], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> virusList, wallList;

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

int solve() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for(pair<int, int> b: virusList) {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for(int i=0; i < n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && a[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main() { 
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j});
            if(a[i][j] == 0) wallList.push_back({i, j});
        }
    }

    for(int i=0; i<wallList.size(); i++) {
        for(int j=0; j<i; j++) {
            for(int k=0; k<j; k++) {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
                a[wallList[i].first][wallList[i].second] = 0;
            }
        }
    }
    cout << ret << '\n';
}
