#include <bits/stdc++.h>
using namespace std;

const int MAX = 1501;
int r, c, day, y, x;
char a[MAX][MAX];
queue<pair<int, int>> swanQ, tempSwanQ;
queue<pair<int, int>> waterQ, tempWaterQ;
int visitedWater[MAX][MAX], visitedSwan[MAX][MAX];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void queueClear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> emptyQ;
    swap(q, emptyQ);
}

bool isSwanMeeting() {
    while (swanQ.size()) {
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (nx < 0 || ny < 0 || nx >= c || ny >= r || visitedSwan[ny][nx]) continue;
            visitedSwan[ny][nx] = 1;
            if (a[ny][nx] == '.')
                swanQ.push({ny, nx});
            else if (a[ny][nx] == 'X')
                tempSwanQ.push({ny, nx});
            else if (a[ny][nx] == 'L')
                return true;
        }
    }
    return false;
}

void waterMelting() {
    while (waterQ.size()) {
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (nx < 0 || ny < 0 || nx >= c || ny >= r || visitedWater[ny][nx]) continue;
            if (a[ny][nx] == 'X') {
                visitedWater[ny][nx] = 1;
                tempWaterQ.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

int main() {
    cin >> r >> c;
    int swanY = 0;
    int swanX = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L') {
                swanY = i;
                swanX = j;
            }
            if (a[i][j] == '.' || a[i][j] == 'L') visitedWater[i][j] = 1, waterQ.push({i, j});
        }
    }

    swanQ.push({swanY, swanX});
    visitedSwan[swanY][swanX] = 1;
    while (true) {
        if (isSwanMeeting()) break;
        waterMelting();
        swanQ = tempSwanQ;
        waterQ = tempWaterQ;
        queueClear(tempSwanQ);
        queueClear(tempWaterQ);
        day++;
    }
    cout << day << '\n';
    return 0;
}