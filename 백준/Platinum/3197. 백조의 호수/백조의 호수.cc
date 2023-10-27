#include <bits/stdc++.h>
using namespace std;

const int MAX = 1501;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
char a[MAX][MAX];
queue<pair<int, int>> waterQ, swanQ, waterTempQ, swanTempQ;
int visitedWater[MAX][MAX], visitedSwan[MAX][MAX];
int y, x, r, c, ret;

void initQueue(queue<pair<int, int>> &q) {
    queue<pair<int, int>> newQueue;
    swap(q, newQueue);
}

bool isValidXY(int y, int x) {
    if (y < 0 || x < 0 || y >= r || x >= c)
        return false;
    else
        return true;
}

void waterMelting() {
    while (waterQ.size()) {
        tie(y, x) = waterQ.front();
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!isValidXY(ny, nx) || visitedWater[ny][nx]) continue;
            if (a[ny][nx] == 'X') {
                visitedWater[ny][nx] = 1;
                waterTempQ.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

bool isSwanMeeting() {
    while (swanQ.size()) {
        tie(y, x) = swanQ.front();
        swanQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!isValidXY(ny, nx) || visitedSwan[ny][nx]) continue;
            visitedSwan[ny][nx] = 1;
            if (a[ny][nx] == '.')
                swanQ.push({ny, nx});
            else if (a[ny][nx] == 'X')
                swanTempQ.push({ny, nx});
            else if (a[ny][nx] == 'L')
                return true;
        }
    }
    return false;
}

int main() {
    int swanY = 0, swanX = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L') {
                swanY = i;
                swanX = j;
            }
            if (a[i][j] == '.' || a[i][j] == 'L') {
                visitedWater[i][j] = 1, waterQ.push({i, j});
            }
        }
    }

    swanQ.push({swanY, swanX});
    visitedSwan[swanY][swanX] = 1;

    while (true) {
        if (isSwanMeeting()) break;
        waterMelting();
        waterQ = waterTempQ;
        swanQ = swanTempQ;
        initQueue(waterTempQ);
        initQueue(swanTempQ);
        ret++;
    }

    cout << ret << '\n';
    return 0;
}