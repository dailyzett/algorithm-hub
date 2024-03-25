#include <bits/stdc++.h>
using namespace std;

typedef long ll;
ll x, y, low, high, ret = -1;

bool check(ll mid) {
    ll initScore = y * 100 / x;
    ll currentScore = (y + mid) * 100 / (x + mid);

    return initScore < currentScore;
}

int main() {
    cin >> x >> y;

    low = 1;
    high = 1000000000;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}