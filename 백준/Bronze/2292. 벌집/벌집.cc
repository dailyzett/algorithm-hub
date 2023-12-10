#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 1;
    if (n == 1) {
        cout << cnt << '\n';
        return 0;
    }

    int six = 6;
    int end = 1;

    while (true) {
        end += six;
        cnt++;

        if (n <= end) break;
        six += 6;
    }
    cout << cnt << '\n';
}