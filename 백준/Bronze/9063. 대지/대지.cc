#include <bits/stdc++.h>
using namespace std;

int n;
int max_y = INT_MIN, max_x = INT_MIN;
int min_y = INT_MAX, min_x = INT_MAX;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        max_x = max(x, max_x);
        max_y = max(y, max_y);

        min_x = min(x, min_x);
        min_y = min(y, min_y);
    }
    cout << (max_x - min_x) * (max_y - min_y) << '\n';
}