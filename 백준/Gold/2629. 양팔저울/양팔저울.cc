#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> chu;
vector<int> gusle;
vector<vector<bool>> dp;
const int MAX_WEIGHT = 40000;

void solve() {
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int weight = chu[i];
        for (int j = MAX_WEIGHT; j >= 0; j--) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                if (j + weight <= MAX_WEIGHT) dp[i + 1][j + weight] = true;
                if (j >= weight)
                    dp[i + 1][j - weight] = true;
                else
                    dp[i + 1][weight - j] = true;
            }
        }
    }
}

bool isCheck(int num) {
    if (num > MAX_WEIGHT) return false;
    for (int i = 0; i <= n; i++) {
        if (dp[i][num]) return true;
    }
    return false;
}

int main() {
    cin >> n;
    chu.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> chu[i];
    }
    cin >> m;
    gusle.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> gusle[i];
    }

    dp.resize(n + 1, vector<bool>(MAX_WEIGHT + 1, false));

    solve();
    for (int i = 0; i < m; i++) {
        if (isCheck(gusle[i])) {
            cout << "Y" << ' ';
        } else {
            cout << "N" << ' ';
        }
    }
    return 0;
}