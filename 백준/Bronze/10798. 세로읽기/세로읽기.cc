#include <bits/stdc++.h>
using namespace std;

int ch[5][15];
int main() {
    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            ch[i][j] = s[j];
        }
    }

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (ch[i][j] == 0) continue;
            cout << (char)ch[i][j];
        }
    }
    cout << '\n';
}