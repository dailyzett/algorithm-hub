#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, f;
    cin >> n >> f;

    n = (n / 100) * 100;

    while (n % f != 0) {
        n++;
    }

    cout << setw(2) << setfill('0') << n % 100 << '\n';

    return 0;
}