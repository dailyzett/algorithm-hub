#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    for (int i : v) cout << i << '\n';
}