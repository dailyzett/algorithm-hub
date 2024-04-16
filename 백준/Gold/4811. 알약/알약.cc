#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[31][31];

ll go(ll w, ll h) {
    if (dp[w][h]) return dp[w][h];
    if (!w) return dp[w][h] = 1;

    if (w) dp[w][h] += go(w - 1, h + 1);
    if (h) dp[w][h] += go(w, h - 1);
    return dp[w][h];
}

int main() {
    ll n;
    while (true) {
        cin >> n;
        if (!n) break;
        cout << go(n, 0) << '\n';
    }
}