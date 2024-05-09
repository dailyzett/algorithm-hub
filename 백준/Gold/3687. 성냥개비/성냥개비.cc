#include <bits/stdc++.h>
using namespace std;

int n;
string dp[101];
const string MAX_STR = "111111111111111111111111111111111111111111111111119";
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string min_str(string a, string b) {
    if (a.size() == b.size()) return (a < b ? a : b);
    if (a.size() < b.size()) return a;
    return b;
}

string findMax(int num) {
    string ret = "";
    if (num & 1) {
        ret += '7';
        num -= 3;
    }
    while (num) {
        ret += '1';
        num -= 2;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;

    fill(dp, dp + 104, MAX_STR);
    dp[0] = "";
    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i - a[j] < 0) continue;
            if (j == 0 && dp[i - a[j]] == "") continue;
            dp[i] = min_str(dp[i], dp[i - a[j]] + to_string(j));
        }
    }
    while (t--) {
        cin >> n;
        cout << dp[n] << ' ' << findMax(n) << '\n';
    }
    return 0;
}