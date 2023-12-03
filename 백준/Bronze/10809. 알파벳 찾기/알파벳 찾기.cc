#include <bits/stdc++.h>
using namespace std;

int a[26];
int main() {
    string s;
    cin >> s;
    fill(a, a + 26, -1);

    for (int i = 0; i < s.size(); i++) {
        if (a[s[i] - 'a'] == -1) {
            a[s[i] - 'a'] = i;
        }
    }

    for (int i : a) cout << i << ' ';
    return 0;
}