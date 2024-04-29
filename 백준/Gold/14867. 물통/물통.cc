#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map<pair<int, int>, int> m;
queue<pair<int, int>> q;

int main() {
    cin >> a >> b >> c >> d;

    q.push({0, 0});
    m[{0, 0}] = 1;
    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (!m[{a, y}]) {
            m[{a, y}] = m[{x, y}] + 1;
            q.push({a, y});
        }

        if (!m[{x, b}]) {
            m[{x, b}] = m[{x, y}] + 1;
            q.push({x, b});
        }

        if (!m[{0, y}]) {
            m[{0, y}] = m[{x, y}] + 1;
            q.push({0, y});
        }

        if (!m[{x, 0}]) {
            m[{x, 0}] = m[{x, y}] + 1;
            q.push({x, 0});
        }

        int new_x = min(x + y, a);
        int new_y = max(0, x + y - a);
        if (!m[{new_x, new_y}]) {
            m[{new_x, new_y}] = m[{x, y}] + 1;
            q.push({new_x, new_y});
        }

        new_x = max(0, x + y - b);
        new_y = min(x + y, b);
        if (!m[{new_x, new_y}]) {
            m[{new_x, new_y}] = m[{x, y}] + 1;
            q.push({new_x, new_y});
        }
    }

    if (m[{c, d}])
        cout << m[{c, d}] - 1 << '\n';
    else
        cout << -1 << '\n';

    return 0;
}