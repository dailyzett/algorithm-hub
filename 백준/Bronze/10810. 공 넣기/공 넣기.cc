#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[101];
int main() {
    cin >> n >> m;

    for (int z = 0; z < m; z++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int x = i; x <= j; x++) {
            a[x] = k;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}