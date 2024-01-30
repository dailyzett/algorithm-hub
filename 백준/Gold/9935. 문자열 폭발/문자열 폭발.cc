#include <bits/stdc++.h>
using namespace std;

string s;
string boom;
char ret[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string replaced = "";

    cin >> s;
    cin >> boom;

    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        ret[idx++] = s[i];

        if (ret[idx - 1] == boom[boom.size() - 1]) {
            if (idx < boom.size()) continue;

            bool isBoom = true;
            for (int j = 0; j < boom.size(); j++) {
                if (boom[j] != ret[idx - boom.size() + j]) {
                    isBoom = false;
                    break;
                }
            }

            if (isBoom) idx -= boom.size();
        }
    }

    if (!idx)
        cout << "FRULA";
    else {
        for (int i = 0; i < idx; i++) {
            cout << ret[i];
        }
    }
    return 0;
}