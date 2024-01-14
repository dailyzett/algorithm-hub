#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, string>> vs;
    for (int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;
        vs.push_back({a, s});
    }

    stable_sort(vs.begin(), vs.end(), [](const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });

    for (auto p : vs) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}