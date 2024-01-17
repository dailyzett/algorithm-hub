#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> num_cards;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num_cards[num] = 1;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (num_cards[num] >= 1)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}