#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }

    vector<int> temp(v);
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    map<int, int> m;
    for (int i = 0; i < temp.size(); i++) {
        m[temp[i]] = i;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << m[v[i]] << ' ';
    }
    cout << '\n';
}