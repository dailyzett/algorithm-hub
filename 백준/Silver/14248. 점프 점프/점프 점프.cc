#include <bits/stdc++.h>
using namespace std;

int a[100001], n, s, visited[100001], ret;

void go(int idx) {
    if (idx < 1 || idx > n || visited[idx]) return;
    visited[idx] = 1;
    go(idx - a[idx]);
    go(idx + a[idx]);
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