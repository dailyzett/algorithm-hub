#include <bits/stdc++.h>
using namespace std;

#define MAX_N 16
int n;
int w[MAX_N][MAX_N];
int dp[MAX_N][1 << MAX_N];
const int INF = 987654321;

/**
 * {a,b,c} -> d
 * {a,c,b} -> d
 *
 * 어디로 가든지 최소값의 경로를 구해서 d 로 가는 길을 합산하면 되므로 순서가 상관이 없다.
 * 각 도시들을 방문했는지 안했는지에 대한 체크를 비트마스킹으로 진행해야한다.
 * 비트마스킹으로 진행하지 않으면 MAX_N 차원의 배열의 선언이 필요하기 때문이다.
 */

int go(int here, int visited) {
    if (visited == (1 << n) - 1) {
        return w[here][0] ? w[here][0] : INF;
    }

    int &ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        if (w[here][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + w[here][i]);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << '\n';
    return 0;
}