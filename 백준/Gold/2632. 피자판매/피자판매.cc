#include <bits/stdc++.h>
using namespace std;

int p, m, n;
int a[1001], b[1001], psumA[2002], psumB[2002];
map<int, int> aCnt, bCnt;

// n: 피자의 원판 수
// psum: 누적합으로 계산된 배열
void makePizza(int n, int psum[], map<int, int> &mp) {
    // 원판을 전체적으로 순회한다.
    for (int i = 1; i <= n; i++) {
        // 만약 i 사이즈가 2라면 [1,2] [2,3] [3,4] 이런식으로 가야된다
        // 즉 start를 1씩 증가시켜야 한다.
        for (int start = i; start <= n + i - 1; start++) {
            int sum = psum[start] - psum[start - i];
            mp[sum]++;
            if (i == n) break;
        }
    }
}

int main() {
    cin >> p >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        psumA[i] = psumA[i - 1] + a[i];
    }
    for (int i = m + 1; i <= 2 * m; i++) {
        psumA[i] = psumA[i - 1] + a[i - m];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        psumB[i] = psumB[i - 1] + b[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        psumB[i] = psumB[i - 1] + b[i - n];
    }

    makePizza(m, psumA, aCnt);
    makePizza(n, psumB, bCnt);

    int ret = aCnt[p] + bCnt[p];
    for (int i = 1; i < p; i++) {
        ret += (aCnt[i] * bCnt[p - i]);
    }
    cout << ret << '\n';
}