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

    for (int i = 0; i < zero_counter; i++) {
        cout << '0';
    }
    for (int i = 0; i < one_counter; i++) {
        cout << '1';
    }
    cout << '\n';
    return 0;
}