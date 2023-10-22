#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MV = 200000;
int visited[MV+2];
int prev1[MV+2];
vector<int> v;

int main() {
    cin >> n >> k;
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(q.size()) {
        int here = q.front();
        q.pop();
        if (here == k) 
            break;        
        for(int next : {here + 1, here - 1, here * 2}) {
            if (next < 0 || next > MV || visited[next])
                continue;
            visited[next] = visited[here] + 1;
            prev1[next] = here;
            q.push(next);            
        }
    }
    for(int i = k; i != n; i = prev1[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << visited[k] - 1 << '\n';
    for(int i : v) cout << i << ' ';
}