#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end(), greater<int>());
    cout << v[k - 1] << '\n';
}