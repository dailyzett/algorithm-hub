#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << ' ';

    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];
        if (!visited[next]) dfs(next);
    }
}

void bfs(int v) {
    queue<int> q;
    memset(visited, false, sizeof(visited));

    q.push(v);
    visited[v] = true;

    while (q.size()) {
        v = q.front();
        cout << v << ' ';
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            int next = graph[v][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';
    return 0;
}