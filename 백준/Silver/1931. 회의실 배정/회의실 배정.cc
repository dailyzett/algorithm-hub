#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, from, to;
    int ret = 1;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());

    from = v[0].second;
    to = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second < to) continue;
        from = v[i].second;
        to = v[i].first;
        ret++;
    }

    cout << ret << '\n';
    return 0;
}