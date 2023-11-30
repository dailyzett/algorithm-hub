#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> ints;
int main() {
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ints.push_back(temp);
    }

    for (int i : ints) {
        if (i < x) {
            cout << i << " ";
        }
    }
}