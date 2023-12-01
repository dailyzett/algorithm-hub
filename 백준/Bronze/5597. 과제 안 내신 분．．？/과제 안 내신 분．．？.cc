#include <bits/stdc++.h>
using namespace std;

int n;
int a[30];
int main() {
    for (int i = 0; i < 28; i++) {
        cin >> n;
        a[n - 1] = 1;
    }

    for (int i = 0; i < 30; i++) {
        if (a[i] == 0) {
            cout << i + 1 << '\n';
        }
    }
}