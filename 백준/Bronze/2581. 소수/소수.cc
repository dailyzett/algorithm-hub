#include <bits/stdc++.h>
using namespace std;

int m, n;
int main() {
    cin >> m >> n;

    vector<int> num;
    for (int i = m; i <= n; i++) {
        num.push_back(i);
    }

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int sum = 0;
    int min_num = INT_MAX;
    for (int i = 0; i < num.size(); i++) {
        if (isPrime[num[i]]) {
            min_num = min(min_num, num[i]);
            sum += num[i];
        }
    }

    if (min_num == INT_MAX)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << min_num << '\n';
}