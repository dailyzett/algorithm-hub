#include <bits/stdc++.h>
using namespace std;

int ret, n;
struct Board {
    int a[24][24];

    void rotate90() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }

    void _move() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            int flag = 0, c = -1;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) continue;
                if (flag && a[i][j] == temp[i][c]) {
                    temp[i][c] *= 2;
                    flag = 0;
                } else {
                    temp[i][++c] = a[i][j];
                    flag = 1;
                }
            }
            for (c++; c < n; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }

    void getMax() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board c, int here) {
    if (here == 5) {
        c.getMax();
        return;
    }

    for (int i = 0; i < 4; i++) {
        Board d = c;
        d._move();
        go(d, here + 1);
        c.rotate90();
    }
    return;
}

int main() {
    cin >> n;
    Board c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c.a[i][j];
        }
    }
    go(c, 0);
    cout << ret << '\n';

    return 0;
}