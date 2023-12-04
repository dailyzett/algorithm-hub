#include <bits/stdc++.h>
using namespace std;

int a[26];
int ret = INT_MIN;
int main() {
    string s;
    cin >> s;
    for (char c : s) {
        a[toupper(c) - 'A']++;
    }

    for (int i : a) {
        ret = max(ret, i);
    }

    int cnt = 0;
    for (int i : a) {
        if (i == ret) cnt++;
    }

    if (cnt > 1)
        cout << '?' << '\n';
    else {
        for (int i = 0; i < 26; i++) {
            if (a[i] == ret) cout << (char)(i + 'A');
        }
    }
}