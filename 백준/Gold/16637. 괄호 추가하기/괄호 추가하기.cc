#include <bits/stdc++.h>
using namespace std;

int n, ret = INT_MIN;
string s;
vector<char> oper;
vector<char> num;

int cal(char a, int b, int c) {
    if(a == '+') return b + c;
    if(a == '*') return b * c;
    if(a == '-') return b - c;
    else return 0;
}

void go(int idx, int result) {
    if(idx == num.size() - 1) {
        ret = max(ret, result);
        return;
    }

    go(idx + 1, cal(oper[idx], result, num[idx + 1]));
    if(idx + 2 < num.size()) {
        int temp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]);
        go(idx + 2, cal(oper[idx], result, temp));
    }

    return;
}

int main() {
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++) {
        if(s[i] == '+' || s[i] == '*' || s[i] == '-') oper.push_back(s[i]);
        else num.push_back(s[i] - '0');
    }

    go(0, num[0]);
    cout << ret << '\n';
    return 0;
}