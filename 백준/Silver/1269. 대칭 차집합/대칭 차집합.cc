#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, temp;
    unordered_set<int> a, b;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (a.find(temp) != a.end()) {
            a.erase(temp);
        } else {
            b.insert(temp);
        }
    }

    cout << a.size() + b.size() << '\n';
    return 0;
}