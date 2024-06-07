#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin >> s;

    // 1. s 의 문자열 중에 0을 반토막, 1을 반토막 낸다.
    int zero_counter = 0;
    int one_counter = 0;
    for (char c : s) {
        if (c - '0' == 0) zero_counter++;
        if (c - '0' == 1) one_counter++;
    }
    zero_counter /= 2;
    one_counter /= 2;

    int len = s.size() - 1;
    bool is_removed[502] = {false};
    while (zero_counter) {
        if (s[len] == '0') {
            zero_counter--;
            is_removed[len] = true;
        }
        len--;
    }

    len = 0;
    while (one_counter) {
        if (s[len] == '1') {
            one_counter--;
            is_removed[len] = true;
        }
        len++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!is_removed[i]) cout << s[i];
    }
    return 0;
}