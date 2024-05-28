#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<char> c;
int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        c.push_back(s[i]);
    }

    int totalRed = count(c.begin(), c.end(), 'R');
    int totalBlue = count(c.begin(), c.end(), 'B');

    int leftRedBlock = 0;
    int leftBlueBlock = 0;
    if (c[0] == 'R') {
        for (int i = 0; i < n && c[i] == 'R'; i++) leftRedBlock++;
    } else {
        for (int i = 0; i < n && c[i] == 'B'; i++) leftBlueBlock++;
    }

    int rightRedBlock = 0;
    int rightBlueBlock = 0;
    if (c[n - 1] == 'R') {
        for (int i = n - 1; i >= 0 && c[i] == 'R'; i--) rightRedBlock++;
    } else {
        for (int i = n - 1; i >= 0 && c[i] == 'B'; i--) rightBlueBlock++;
    }

    int moveLeftRed = totalRed - leftRedBlock;
    int moveLeftBlue = totalBlue - leftBlueBlock;
    int moveRightRed = totalRed - rightRedBlock;
    int moveRightBlue = totalBlue - rightBlueBlock;

    int ret = min({moveLeftRed, moveLeftBlue, moveRightRed, moveRightBlue});
    cout << ret << '\n';
    return 0;
}