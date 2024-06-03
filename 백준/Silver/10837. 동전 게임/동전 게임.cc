#include <bits/stdc++.h>
using namespace std;

int k, c, n, m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> m >> n;

        int remain_game = k - max(n, m);
        int diff = abs(n - m);

        if (m == n) {
            cout << "1" << '\n';
            continue;
        }
        if (m > n) {
            if (diff - remain_game <= 2) {
                cout << "1" << '\n';
                continue;
            }
            cout << "0" << '\n';
            continue;
        }

        if (diff - remain_game <= 1) {
            cout << "1" << '\n';
            continue;
        }

        cout << 0 << '\n';
    }

    return 0;
}