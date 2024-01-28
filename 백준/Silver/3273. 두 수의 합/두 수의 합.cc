#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());

    int x;
    cin >> x;

    int l = 0, r = n - 1;
    int ret = 0;
    while (l < r) {
        if (v[l] + v[r] == x) {
            r--;
            ret++;
        } else if (v[l] + v[r] > x)
            r--;
        else if (v[l] + v[r] < x)
            l++;
    }

    cout << ret << '\n';
    return 0;
}