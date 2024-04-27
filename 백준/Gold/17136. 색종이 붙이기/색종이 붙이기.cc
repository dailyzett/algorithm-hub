#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int board[n][n];
const int INF = 987654321;
int ret = INF;
map<int, int> mp;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int y, int x, int paperSize) {
    if (y + paperSize > n || x + paperSize > n) return false;
    for (int i = y; i < y + paperSize; i++) {
        for (int j = x; j < x + paperSize; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void draw(int y, int x, int paperSize, int num) {
    for (int i = y; i < y + paperSize; i++) {
        for (int j = x; j < x + paperSize; j++) {
            board[i][j] = num;
        }
    }
}

void go(int y, int x, int cnt) {
    if (cnt >= ret) return;
    if (x == n) {
        go(y + 1, 0, cnt);
        return;
    }

    if (y == n) {
        ret = min(ret, cnt);
        return;
    }

    if (board[y][x] == 0) {
        go(y, x + 1, cnt);
        return;
    }

    for (int i = 5; i > 0; i--) {
        if (mp[i] == 5) continue;
        if (check(y, x, i)) {
            mp[i]++;
            draw(y, x, i, 0);
            go(y, x + i, cnt + 1);
            draw(y, x, i, 1);
            mp[i]--;
        }
    }
    return;
}

int main() {
    fast();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    go(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << '\n';
}