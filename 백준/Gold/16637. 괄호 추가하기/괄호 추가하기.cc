#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> num;
vector<char> oper;

int calc(char oper, int num1, int num2)
{
    if (oper == '+')
        return num1 + num2;
    if (oper == '-')
        return num1 - num2;
    if (oper == '*')
        return num1 * num2;
    else return 0;
}

void go(int idx, int result) {
    if(idx == num.size() - 1) {
        ret = max(ret, result);
        return;
    }
    go(idx + 1, calc(oper[idx], result, num[idx + 1]));

    if(idx + 2 <= num.size() - 1) {
        int temp = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
        go(idx + 2, calc(oper[idx], result, temp));
    }
    return;
}

int main() {
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++) {
        if(i%2 == 0) num.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    }

    go(0, num[0]);
    cout << ret << '\n';
    return 0;
}