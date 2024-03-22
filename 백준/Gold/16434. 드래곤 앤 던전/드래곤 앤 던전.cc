#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, atk, low, high, ret;
ll t[123457], a[123457], h[123457];

bool check(ll mid) {
    ll maxHp = mid;
    ll initAtk = atk;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            ll cnt = h[i] / initAtk + (h[i] % initAtk ? 1 : 0);
            mid -= (cnt - 1) * a[i];
        } else if (t[i] == 2) {
            mid = min(maxHp, mid + h[i]);
            initAtk += a[i];
        }

        if (mid <= 0) return false;
    }
    return true;
}

int main() {
    cin >> n >> atk;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }

    low = 1;
    high = 1e18 + 4;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ret << '\n';
}