#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a] = true;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (mp[a])
                cout << '1' << '\n';
            else
                cout << '0' << '\n';
        }
    }
    return 0;
}