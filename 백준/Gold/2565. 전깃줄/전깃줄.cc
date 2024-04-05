#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
vector<pair<int, int>> p;
int lis[502], len;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p.push_back({a, b});
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        auto lowerPos = lower_bound(lis, lis + len, p[i].second);
        if (*lowerPos == 0) {
            len++;
        }
        *lowerPos = p[i].second;
    }
    cout << n - len << '\n';
}