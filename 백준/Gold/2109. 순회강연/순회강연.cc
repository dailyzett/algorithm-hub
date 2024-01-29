#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }

    while (pq.size()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << '\n';
    return 0;
}