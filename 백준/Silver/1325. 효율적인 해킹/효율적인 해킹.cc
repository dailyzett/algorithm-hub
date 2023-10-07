#include <bits/stdc++.h>
using namespace std;

const int V = 10002;
int n,m, mx;
vector<int> adj[V];
int visited[V], dp[V];

int go(int here) {
    visited[here] = 1;
    int ret = 1;
    for(int there: adj[here]) {
        if(visited[there] == 1) continue;
        ret += go(there);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        adj[c2].push_back(c1);
    }

    for(int i=1; i<=n; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = go(i);
        mx = max(dp[i], mx);
    }
    
     for(int i=1; i<=n; i++) {
        if(mx == dp[i]) cout << i << " ";
     }
}