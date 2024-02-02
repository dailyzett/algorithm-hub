#include <bits/stdc++.h>
using namespace std;

int n, arrive_time, check_time;
int sum_time;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> arrive_time >> check_time;
        v.push_back({arrive_time, check_time});
    }

    sort(v.begin(), v.end());

    sum_time = v[0].first + v[0].second;
    for (int i = 1; i < n; i++) {
        sum_time = max(sum_time, v[i].first);
        sum_time += v[i].second;
    }
    cout << sum_time << '\n';
    return 0;
}