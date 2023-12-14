#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minValue = INT_MAX;
    minValue = min(minValue, h - y);
    minValue = min(minValue, w - x);
    minValue = min(minValue, x - 0);
    minValue = min(minValue, y - 0);

    cout << minValue << '\n';
}