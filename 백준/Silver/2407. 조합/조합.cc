#include <bits/stdc++.h>
using namespace std;

int n, m;
string string_add(const string &num1, const string &num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int max_len = max(len1, len2);

    int carry = 0;
    string ret = "";
    for (int i = 0; i < max_len; i++) {
        int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        ret += (sum % 10) + '0';
    }
    if (carry) {
        ret += carry + '0';
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin >> n >> m;
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, "0"));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = "1";
        if (i <= m) {
            dp[i][i] = "1";
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            dp[i][j] = string_add(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}