#include <bits/stdc++.h>
using namespace std;

int n, ret;
struct Board {
    int a[21][21];
    void _move() {
        int temp[21][21];
        for (int i = 0; i < n; i++) {
            int c = -1;
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) continue;
                if (flag && a[i][j] == temp[i][c])
                    temp[i][c] *= 2, flag = false;
                else
                    temp[i][++c] = a[i][j], flag = true;
            }
            for (c++; c < n; c++) temp[i][c] = 0;
        }

        memcpy(a, temp, sizeof(a));
    }

    void rotate90() {
        int temp[21][21];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = a[n - j - 1][i];
            }
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
    Board b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b.a[i][j];
        }
    }

    go(b, 0);
    cout << ret << '\n';
    return 0;
}