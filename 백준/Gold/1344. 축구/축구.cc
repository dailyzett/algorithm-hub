#include <bits/stdc++.h>
using namespace std;

const int N = 18;
double A, B;
double dp[N][N][N];
bool isPrime[20];

double go(int idx, int a, int b) {
    if (idx == N) {
        if (isPrime[a] || isPrime[b]) {
            return 1.0;
        } else {
            return 0.0;
        }
    }

    double &ret = dp[idx][a][b];
    if (ret > -0.5) return ret;

    ret = 0.0;
    ret += go(idx + 1, a, b) * (1 - A) * (1 - B);
    ret += go(idx + 1, a + 1, b + 1) * A * B;
    ret += go(idx + 1, a, b + 1) * (1 - A) * B;
    ret += go(idx + 1, a + 1, b) * A * (1 - B);
    return ret;
}

void era() {
    fill(isPrime, isPrime + 20, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= 20; i++) {
        for (int j = i * i; j <= 20; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    cin >> A >> B;
    A /= 100;
    B /= 100;
    memset(dp, -1, sizeof(dp));
    era();
    cout << go(0, 0, 0);
}