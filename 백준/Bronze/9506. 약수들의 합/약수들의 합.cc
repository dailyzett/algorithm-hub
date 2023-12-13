#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    while (true) {
        cin >> n;
        if (n == -1) break;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) v.push_back(i);
        }

        int sum = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            sum += v[i];
        }

        if (sum != n) {
            cout << n << " is NOT perfect.\n";
        } else {
            cout << n << " = ";
            for (int i = 0; i < v.size() - 1; i++) {
                if (i == v.size() - 2) {
                    cout << v[i];
                } else {
                    cout << v[i] << " + ";
                }
            }
            cout << '\n';
        }
    }
}