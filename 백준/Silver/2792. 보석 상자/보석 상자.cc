#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
ll color[300001];
ll ret = INT_MAX;

bool check(ll mid) {
    ll num = 0;
    for (int i = 0; i < m; i++) {
        num += color[i] / mid;
        if (color[i] % mid) num++;
    }
    return n >= num;
}

int main() {
    cin >> n >> m;
    ll low = 1, high = 0, mid;
    for (int i = 0; i < m; i++) {
        cin >> color[i];
        high = max(color[i], high);
    }

    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}