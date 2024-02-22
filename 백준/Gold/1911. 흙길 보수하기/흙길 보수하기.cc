#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<pair<int, int>> p;
int ret, idx, num;

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        p.push_back({start, end});
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        if (p[i].second <= idx) continue;
        if (p[i].first > idx) {
            num = (p[i].second - p[i].first) / l + ((p[i].second - p[i].first) % l ? 1 : 0);
            idx = p[i].first + num * l;
        } else {
            num = (p[i].second - idx) / l + ((p[i].second - idx) % l ? 1 : 0);
            idx = idx + num * l;
        }
        ret += num;
    }
    cout << ret << '\n';
}