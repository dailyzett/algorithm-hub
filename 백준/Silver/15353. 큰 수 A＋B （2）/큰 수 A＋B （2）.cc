#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> ret;

    int sum = 0;
    while (a.size() || b.size() || sum) {
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        ret.push_back(sum % 10);
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    for (int i : ret) cout << i;
    return 0;
}