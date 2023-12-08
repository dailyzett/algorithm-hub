#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            int num = (int)(s[i] - 'A' + 10);
            sum += num * pow(n, s.size() - 1 - i);
        } else {
            int num = (int)(s[i] - '0');
            sum += num * pow(n, s.size() - 1 - i);
        }
    }

    cout << sum << '\n';
    return 0;
}