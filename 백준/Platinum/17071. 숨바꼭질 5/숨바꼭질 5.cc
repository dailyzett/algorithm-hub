#include <bits/stdc++.h>
using namespace std;

int n, k, ret, distancePerSeconds = 1;
const int MAX = 500000;
int visited[2][MAX+1];
int main() {
    bool sameLocation = false;
    cin >> n >> k;
    
    if(n == k) {
        cout << 0 << "\n";
        return 0;
    }
    queue<int> q;
    visited[0][n] = 1;
    q.push(n);
    while(q.size()) {
        k += distancePerSeconds;
        if(k > MAX) break;
        if(visited[distancePerSeconds % 2][k]) {
            sameLocation = true;
            break;
        }

        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int here = q.front(); q.pop();
            for(int next: {here + 1, here - 1, here * 2}) {
                if(next < 0 || next > MAX || visited[distancePerSeconds % 2][next]) continue;
                visited[distancePerSeconds % 2][next] = visited[(distancePerSeconds + 1) % 2][here] + 1;
                if(next == k) {
                    sameLocation = true;
                    break;
                }
                q.push(next);
            }
            if(sameLocation) break;
        }
        if(sameLocation) break;
        distancePerSeconds++;
    }

    if(sameLocation) cout << distancePerSeconds << '\n';
    else cout << -1 << '\n';
    
    return 0;
}