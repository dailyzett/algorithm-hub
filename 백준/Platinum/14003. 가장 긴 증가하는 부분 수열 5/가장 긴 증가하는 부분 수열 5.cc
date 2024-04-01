#include <bits/stdc++.h>
using namespace std;

int n, num, len;
const int INF = 1e9 + 4;
pair<int, int> p[1000004];
stack<int> stk;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastIO();
    cin >> n;
    vector<int> v(n);
    fill(v.begin(), v.end(), INF);
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(v.begin(), v.end(), num);
        int _pos = lowerPos - v.begin();
        if (*lowerPos == INF) len++;
        *lowerPos = num;

        p[i].first = _pos;
        p[i].second = num;
    }

    cout << len << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (p[i].first == len - 1) {
            stk.push(p[i].second);
            len--;
        }
    }

    while (stk.size()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
}