#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n;

    vector<int> v(n);
    int max_num = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        max_num = max(v[i], max_num);
    }

    vector<bool> isPrime(max_num + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= max_num; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int prime_count = 0;
    for (int i : v) {
        if (isPrime[i]) ++prime_count;
    }

    cout << prime_count << '\n';
}