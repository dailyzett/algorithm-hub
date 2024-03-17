#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001];
int low, high, mid, ret;

bool check(int mid) {
    int cnt = 1;
    int temp = mid;
    for (int i = 0; i < n; i++) {
        if (mid - a[i] < 0) {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        low = max(low, a[i]);
    }
    high = 1000000004;

    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
            ret = mid;
        } else
            low = mid + 1;
    }

    cout << ret << '\n';
    return 0;
}