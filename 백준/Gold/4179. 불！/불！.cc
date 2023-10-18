#include <bits/stdc++.h>
using namespace std;

int r,c;
char ch[1002][1002];
int visitedJihoon[1002][1002];
int visitedFire[1002][1002];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int cnt, sy, sx, y, x, ret;
const int INF = 987654321;

int main() {
    cin >> r >> c;
    queue<pair<int, int>> q;
    fill(&visitedFire[0][0], &visitedFire[0][0] + 1002 * 1002, INF);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) {
            cin >> ch[i][j];
            if(ch[i][j] == 'F') {
                visitedFire[i][j] = 1;
                q.push({i, j});
            } else if(ch[i][j] == 'J') {
                sy = i;
                sx = j;
            }
        }
    }

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || ny >= r || nx >= c) continue;
            if(ch[ny][nx] == '#') continue;
            // if(visitedFire[ny][nx]) continue;
            if(visitedFire[ny][nx] != INF) continue;
            visitedFire[ny][nx] = visitedFire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    visitedJihoon[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        if (y == r - 1 || x == c - 1 || y == 0 || x == 0)
        {
            ret = visitedJihoon[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || ny >= r || nx >= c) continue;
            if (visitedJihoon[ny][nx]) continue;
            if (ch[ny][nx] == '#') continue;
            if (visitedFire[ny][nx] <= visitedJihoon[y][x] + 1) continue;
            visitedJihoon[ny][nx] = visitedJihoon[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE";
    return 0;
}