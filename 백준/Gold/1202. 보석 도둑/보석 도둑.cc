#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> bosuk(n);
    vector<ll> bag(k);

    for (int i = 0; i < n; i++) {
        cin >> bosuk[i].first >> bosuk[i].second;
    }

    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }

    sort(bosuk.begin(), bosuk.end());
    sort(bag.begin(), bag.end());

    priority_queue<ll> pq;
    ll ret = 0;
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && bosuk[j].first <= bag[i]) pq.push(bosuk[j++].second);
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << '\n';

    return 0;
}