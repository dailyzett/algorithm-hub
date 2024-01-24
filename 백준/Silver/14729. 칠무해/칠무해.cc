#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> pq;
    for (int i = 0; i < n; i++) {
        double grade;
        cin >> grade;
        pq.push(grade);
    }

    int initSize = min(7, static_cast<int>(pq.size()));
    cout << fixed << setprecision(3);
    for (int i = 0; i < initSize; i++) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}