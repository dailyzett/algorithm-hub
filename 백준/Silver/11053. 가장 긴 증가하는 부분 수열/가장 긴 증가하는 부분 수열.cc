#include <bits/stdc++.h>
using namespace std;

int n, len;

int main() {
    cin >> n;
    vector<int> v(n);
    fill(v.begin(), v.end(), INT_MAX);

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        auto lowerPos = lower_bound(v.begin(), v.end(), input);
        if (*lowerPos == INT_MAX) len++;
        *lowerPos = input;
    }

    cout << len << '\n';
}