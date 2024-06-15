#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adj(n+1);
    vector<int> distances(n+1, -1);
    
    for(const auto &e: edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    distances[1] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int neighbor: adj[node]) {
            if(distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    int max_value = *max_element(distances.begin(), distances.end());
    int ret = count(distances.begin(), distances.end(), max_value);
    return ret;
}