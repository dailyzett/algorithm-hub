#include <bits/stdc++.h>
using namespace std;

int a[100001], n, s, visited[100001], ret;

void go(int idx) {
    if (visited[idx]) return;
    visited[idx] = 1;
    if (idx - a[idx] >= 1) {
        go(idx - a[idx]);
    }

    if (idx + a[idx] <= n) {
        go(idx + a[idx]);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    go(s);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) ret++;
    }
    cout << ret << '\n';
    return 0;
}