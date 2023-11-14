#include <bits/stdc++.h>
using namespace std;

int n;
int ret = INT_MAX;
int pc[20], section[20], visited[20];
vector<int> adj[12];

pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    pair<int, int> ret = {1, pc[here]};
    for (int there : adj[here]) {
        if (visited[there]) continue;
        if (section[there] != value) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pc[i];
    }

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int m;
            cin >> m;
            adj[i].push_back(m);
            adj[m].push_back(i);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) {
        fill(section, section + 20, 0);
        fill(visited, visited + 20, 0);
        int start1 = -1, start2 = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                section[j + 1] = 1;
                start1 = j + 1;
            } else {
                start2 = j + 1;
            }
        }

        pair<int, int> sec1 = dfs(start1, 1);
        pair<int, int> sec2 = dfs(start2, 0);
        if (sec1.first + sec2.first == n) {
            ret = min(ret, abs(sec1.second - sec2.second));
        }
    }

    if (ret == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
    }

    return 0;
}