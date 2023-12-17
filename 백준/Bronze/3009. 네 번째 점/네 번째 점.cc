#include <bits/stdc++.h>
using namespace std;

int x[4];
int y[4];
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    int fx;
    if (x[0] == x[1]) {
        fx = x[2];
    } else if (x[1] == x[2]) {
        fx = x[0];
    } else {
        fx = x[1];
    }

    int fy;
    if (y[0] == y[1]) {
        fy = y[2];
    } else if (y[1] == y[2]) {
        fy = y[0];
    } else {
        fy = y[1];
    }

    cout << fx << ' ' << fy;
    return 0;
}