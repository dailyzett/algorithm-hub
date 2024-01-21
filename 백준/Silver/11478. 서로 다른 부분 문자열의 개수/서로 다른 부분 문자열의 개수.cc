#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    unordered_set<string> subs;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            subs.insert(s.substr(i, j));
        }
    }

    cout << subs.size() << '\n';
    return 0;
}