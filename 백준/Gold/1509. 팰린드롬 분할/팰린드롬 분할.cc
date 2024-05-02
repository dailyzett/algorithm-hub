#include <bits/stdc++.h>
using namespace std;

string s;
int dp[2501][2501], dp2[2502];
const int INF = 987654321;

int go(int here) {
    if (here == s.size()) return 0;
    if (dp2[here] != INF) return dp2[here];
    int &ret = dp2[here];

    for (int i = 1; i + here <= s.size(); i++) {
        if (dp[here][i]) ret = min(ret, go(here + i) + 1);
    }
    return ret;
}

int main() {
    cin >> s;
    int strSize = s.size();

    for (int i = 0; i < strSize; i++) {
        dp[i][1] = 1;
    }

    for (int i = 0; i < strSize - 1; i++) {
        if (s[i] == s[i + 1]) dp[i][2] = 1;
    }

    for (int palSize = 3; palSize <= strSize; palSize++) {
        for (int i = 0; i + palSize <= strSize; i++) {
            if (s[i] == s[i + palSize - 1] && dp[i + 1][palSize - 2]) dp[i][palSize] = 1;
        }
    }

    fill(dp2, dp2 + 2502, INF);
    cout << go(0) << '\n';
    return 0;
}