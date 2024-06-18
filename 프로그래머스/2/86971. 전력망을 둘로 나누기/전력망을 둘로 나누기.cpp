#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;

int dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    int count = 1;
    
    for(int neighbor: adj[node]) {
        if(!visited[neighbor]) {
            count += dfs(neighbor, visited);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    adj.assign(n + 1, vector<int>());
    
    for(vector<int> wire: wires) {
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }
    
    for(vector<int> wire: wires) {
        adj[wire[0]].erase(remove(adj[wire[0]].begin(), adj[wire[0]].end(), wire[1]), adj[wire[0]].end());
        adj[wire[1]].erase(remove(adj[wire[1]].begin(), adj[wire[1]].end(), wire[0]), adj[wire[1]].end());
        
        vector<bool> visited(n+1, false);
        
        int subtree_count = dfs(wire[0], visited);
        int diff = abs(subtree_count - (n - subtree_count));
        
        answer = min(answer, diff);
        
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }

    return answer;
}