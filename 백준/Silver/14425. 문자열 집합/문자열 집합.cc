#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (mp[s] >= 1) cnt++;
    }
    cout << cnt << '\n';
}