#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, v;

    cin >> a >> b >> v;

    int total_distance = v - a;
    int today_distance = a - b;

    int days = ceil((double)total_distance / today_distance) + 1;
    cout << days;
}