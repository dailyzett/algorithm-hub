#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        string s;
        cin >> s;
        string ret = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < r; j++) {
                ret += s[i];
            }
        }
        cout << ret << '\n';
    }
    return 0;
}