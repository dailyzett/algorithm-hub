#include <bits/stdc++.h>
using namespace std;

int n, deadline, ramen;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> deadline >> ramen;
        v.push_back({deadline, ramen});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }

    int ret = 0;
    while (pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}