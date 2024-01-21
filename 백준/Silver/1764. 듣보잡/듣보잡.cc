#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (int i = n + 2; i < n + m + 2; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    vector<string> v;
    int cnt = 0;
    for (auto const &pair : mp) {
        if (pair.second >= 2) {
            cnt++;
            v.push_back(pair.first);
        }
    }

    cout << cnt << '\n';
    for (string s : v) {
        cout << s << '\n';
    }

    return 0;
}