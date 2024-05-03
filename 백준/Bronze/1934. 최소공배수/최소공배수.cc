#include <bits/stdc++.h>
using namespace std;

int t;

int go(int a, int b) {
    int m = max(a, b);
    int gong = 0;
    for (int i = 1; i <= m; i++) {
        if (a % i == 0 && b % i == 0) {
            gong = i;
        }
    }
    int num1 = a / gong;
    int num2 = b / gong;

    return num1 * num2 * gong;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << go(a, b) << '\n';
    }
}