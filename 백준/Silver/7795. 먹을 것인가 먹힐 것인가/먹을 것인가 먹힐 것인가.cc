#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            auto p = lower_bound(b.begin(), b.end(), a[i]);
            cnt += (int)(p - b.begin());
        }

        cout << cnt << '\n';
    }
}