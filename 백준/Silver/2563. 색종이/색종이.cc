#include <bits/stdc++.h>
using namespace std;

int n, ret;
int a[100][100];

void fillDark(int sy, int sx) {
    int ex = sx + 10;
    int ey = sy + 10;
    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            a[i][j] = 1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        fillDark(b, a);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            ret += a[i][j];
        }
    }

    cout << ret << '\n';
}