#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            cout << ' ';
        }

        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}