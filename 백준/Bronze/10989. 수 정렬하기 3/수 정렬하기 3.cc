#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int counts[10001] = {
        0,
    };

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        counts[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < counts[i]; j++) {
            cout << i << '\n';
        }
    }
}