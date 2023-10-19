#include <bits/stdc++.h>
using namespace std;

int n;
int a[3];
int visited[61][61][61];
int mutalAttack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
struct A {
    int a,b,c;
};

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    queue<A> q;
    
    int a1 = a[0];
    int a2 = a[1];
    int a3 = a[2];

    visited[a1][a2][a3] = 1;
    q.push({a1, a2, a3});
    while(q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i=0; i<6; i++) {
            int na = max(0, a - mutalAttack[i][0]);
            int nb = max(0, b - mutalAttack[i][1]);
            int nc = max(0, c - mutalAttack[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    cout << visited[0][0][0] - 1 << '\n';
}