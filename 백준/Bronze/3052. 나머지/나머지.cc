#include <bits/stdc++.h>
using namespace std;

int a[1001];
int main() {
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        int ret = n % 42;
        a[ret]++;
    }

    int ret = 0;
    for (int i : a) {
        if (i > 0) ret++;
    }
    cout << ret;
}