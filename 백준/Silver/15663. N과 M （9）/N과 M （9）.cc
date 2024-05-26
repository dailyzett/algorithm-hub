#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> current_comb;
    set<vector<int>> unique_comb;
    do {
        current_comb.assign(v.begin(), v.begin() + m);
        unique_comb.insert(current_comb);
    } while (next_permutation(v.begin(), v.end()));

    for (vector<int> u : unique_comb) {
        for (int num : u) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}