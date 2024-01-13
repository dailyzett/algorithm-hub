#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for (string& s : v) {
        cin >> s;
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });

    v.erase(unique(v.begin(), v.end()), v.end());

    for (string s : v) {
        cout << s << '\n';
    }
}