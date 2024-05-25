#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (prev_permutation(v.begin(), v.end())) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}