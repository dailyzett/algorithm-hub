#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    vector<int> v;
    for (char c : str) {
        v.push_back(c - '0');
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i : v) cout << i;
    cout << '\n';
}