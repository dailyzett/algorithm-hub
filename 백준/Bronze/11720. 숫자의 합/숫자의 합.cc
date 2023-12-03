#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum = 0;
    for (char c : s) {
        int temp = c - '0';
        sum += temp;
    }
    cout << sum;
}