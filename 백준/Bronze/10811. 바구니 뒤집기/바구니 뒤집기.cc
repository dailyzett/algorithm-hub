#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[102];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        reverse(a + left, a + right + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}