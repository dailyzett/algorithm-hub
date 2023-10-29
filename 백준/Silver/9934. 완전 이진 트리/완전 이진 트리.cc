#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> v;
vector<int> ret[14];

void go(int start, int end, int level) {
    if (start > end) return;
    int middle = (start + end) / 2;
    if (start == middle) {
        ret[level].push_back(v[start]);
        return;
    }
    ret[level].push_back(v[middle]);
    go(start, middle - 1, level + 1);
    go(middle + 1, end, level + 1);
    return;
}

int main() {
    cin >> k;
    int m = pow(2, k) - 1;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    go(0, m, 1);

    for (int i = 1; i <= k; i++) {
        for (int j : ret[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}