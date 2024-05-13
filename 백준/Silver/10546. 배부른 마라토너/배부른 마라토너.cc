#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }

    for (auto &m : mp) {
        if (m.second > 0) {
            cout << m.first << '\n';
            break;
        }
    }
    return 0;
}