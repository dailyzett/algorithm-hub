#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int temp = v[a - 1];
        v[a - 1] = v[b - 1];
        v[b - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}