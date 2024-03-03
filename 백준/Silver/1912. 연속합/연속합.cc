#include <bits/stdc++.h>
using namespace std;

int n, sum;
int ret = INT_MIN;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }
    cout << ret << '\n';
}