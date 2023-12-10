#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int floor = 0;
    int remainder = 0;
    while (true) {
        x -= floor;
        if (x < 0 || x == 0) {
            remainder = x;
            break;
        }
        floor++;
    }
    int r = abs(remainder);

    // cout << "대각선 수: " << floor << '\n';
    // cout << "몇번째: " << r << '\n';

    int bunja = 0;
    int bunmo = 0;

    if (floor % 2 == 0) {
        bunmo = 1 + r;
        bunja = floor - r;
    } else {
        bunmo = floor - r;
        bunja = 1 + r;
    }
    cout << bunja << "/" << bunmo;
}