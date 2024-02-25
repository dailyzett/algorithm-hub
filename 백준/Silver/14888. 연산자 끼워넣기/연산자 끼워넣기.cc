#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num(12);
vector<int> op(4);

int maxi = INT_MIN;
int mini = INT_MAX;

void go(int now, int idx) {
    if (idx == n) {
        maxi = max(maxi, now);
        mini = min(mini, now);
    }

    if (op[0] > 0) {
        op[0]--;
        go(now + num[idx], idx + 1);
        op[0]++;
    }

    if (op[1] > 0) {
        op[1]--;
        go(now - num[idx], idx + 1);
        op[1]++;
    }

    if (op[2] > 0) {
        op[2]--;
        go(now * num[idx], idx + 1);
        op[2]++;
    }

    if (op[3] > 0) {
        if (num[idx] == 0) return;
        op[3]--;
        go(now / num[idx], idx + 1);
        op[3]++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    go(num[0], 1);
    cout << maxi << '\n' << mini << '\n';
    return 0;
}