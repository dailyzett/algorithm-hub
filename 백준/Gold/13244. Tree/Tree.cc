#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> adj[1004];
int visited[1004];

void dfs(int here) {
    visited[here] = 1;
    for (int there : adj[here]) {
        if (visited[there] == 0) dfs(there);
    }
    return;
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int i = 0; i < 1004; i++) adj[i].clear();
        fill(visited, visited + 1004, 0);

        cin >> n >> m;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i);
                cnt++;
            }
        }

        if (m == n - 1 && cnt == 1)
            cout << "tree" << '\n';
        else
            cout << "graph" << '\n';
    }
    return 0;
}