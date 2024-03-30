#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, c, l, low, high, ret;
ll total;
ll a[1000004];

bool check(ll mid) {
    ll cnt = 0;
    for (int i = 0; i < s; i++) {
        cnt += a[i] / mid;
    }
    return cnt >= c;
}

int main() {
    cin >> s >> c;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
        total += a[i];
    }

    high = 1e9;
    low = 1;
    while (low <= high) {
        ll mid = (low + high) / (1LL * 2);
        if (check(mid)) {
            low = mid + 1;
            ret = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << total - ret * c << '\n';
    return 0;
}