#include <bits/stdc++.h>
using namespace std;

int x, n;
int main() {
    int ret = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ret += a * b;
    }

    if (ret == x)
        cout << "Yes\n";
    else
        cout << "No\n";
}