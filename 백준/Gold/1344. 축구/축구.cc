#include <bits/stdc++.h>
using namespace std;

double a, b;
double dp[20][20][20];
bool isPrime[20];

double go(int x, int y, int cnt) {
    if (cnt == 18) return isPrime[x] || isPrime[y] ? 1.0 : 0.0;
    double &ret = dp[x][y][cnt];
    if (ret > -0.5) return ret;
    ret = 0.0;
    ret += go(x, y, cnt + 1) * (1 - a) * (1 - b);
    ret += go(x + 1, y, cnt + 1) * a * (1 - b);
    ret += go(x, y + 1, cnt + 1) * (1 - a) * b;
    ret += go(x + 1, y + 1, cnt + 1) * a * b;
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
    cin >> a >> b;

    a /= 100;
    b /= 100;

    memset(dp, -1, sizeof(dp));
    era();
    double answer = go(0, 0, 0);
    printf("%.6lf", answer);
}