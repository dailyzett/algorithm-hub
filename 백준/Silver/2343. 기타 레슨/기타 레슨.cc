#include <bits/stdc++.h>
using namespace std;

int n, m;
int high, low, mx, ret;
int a[100001];

bool check(int pMid) {
    if (mx > pMid) return false;
    int cnt = 0;
    int temp = pMid;
    for (int i = 0; i < n; i++) {
        if (pMid - a[i] < 0) {
            pMid = temp;
            cnt++;
        }
        pMid -= a[i];
    }
    if (pMid != temp) cnt++;
    return cnt <= m;
}

int main() {
    int sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(a[i], mx);
    }
    high = sum;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}