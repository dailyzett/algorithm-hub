#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin >> s;

    int cnt = 0;
    for (char c : s) {
        if (cnt > 0 && cnt % 10 == 0) cout << '\n';
        cout << c;
        cnt++;
    }

    return 0;
}