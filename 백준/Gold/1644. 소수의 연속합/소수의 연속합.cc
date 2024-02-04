#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<int> prime;
void findPrimes(int maxNum) {
    vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = isPrime[1] = 1;

    for (int i = 2; i * i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= maxNum; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int startIdx = 0;
    int endIdx = 0;
    int sum = 0;

    findPrimes(n);

    while (true) {
        if (sum >= n)
            sum -= prime[startIdx++];
        else if (endIdx == prime.size())
            break;
        else
            sum += prime[endIdx++];
        if (sum == n) ret++;
    }

    cout << ret << '\n';
    return 0;
}