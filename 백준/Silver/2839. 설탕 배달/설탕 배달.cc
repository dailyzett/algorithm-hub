#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n / 5; i >= 0; i--) {
        if ((n - i * 5) % 3 == 0) {
            cout << i + ((n - i * 5) / 3) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}