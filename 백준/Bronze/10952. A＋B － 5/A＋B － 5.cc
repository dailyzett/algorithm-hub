#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        cout << a + b << '\n';
    }
    return 0;
}