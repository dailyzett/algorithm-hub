#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    for (int &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());
    int sum = 0;
    for (int i : v) {
        sum += i;
    }
    cout << sum / 5 << '\n';
    cout << v[2] << '\n';
    return 0;
}