#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int q = n / 25;
        n %= 25;

        int d = n / 10;
        n %= 10;

        int nickel = n / 5;
        n %= 5;

        int penny = n / 1;
        n %= 1;

        cout << q << ' ' << d << ' ' << nickel << ' ' << penny << ' ';
        cout << '\n';
    }

    return 0;
}