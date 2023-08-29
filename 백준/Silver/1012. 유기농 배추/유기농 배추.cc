#include <bits/stdc++.h>
using namespace std;

const int max_n = 54;
int a[max_n][max_n];
int visited[max_n][max_n];
int t, m, n, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ret;

void go(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
        if(visited[ny][nx] == 0) {
            go(ny, nx);
        }
    }
    return;
}

int main()
{
    cin >> t;
    while(t--) {
        fill(&a[0][0], &a[0][0] + 54 * 54, 0);
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        cin >> m >> n >> k;
        for(int i=0; i<k; i++) {
            int y;
            int x;
            cin >> x >> y;
            a[y][x] = 1;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visited[i][j] == 0 && a[i][j] == 1) {
                    ret++;
                    go(i,j);
                }
            }
        }

        cout << ret << '\n';
        ret = 0;
    }
}