#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int temp = b;
    while (true) {
        int remainder = temp % 10;
        cout << a * remainder << '\n';
        temp /= 10;

        if (!temp) break;
    }
    cout << a * b << '\n';
}
