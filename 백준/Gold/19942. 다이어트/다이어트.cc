#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
int p, f, s, v, c;
int a[16][6];
vector<int> retV;
int retPrice = INT_MAX;
map<int, vector<vector<int>>> retMap;

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        int tp = 0, tf = 0, ts = 0, tv = 0;
        int totalPrice = 0;
        vector<int> tempV;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tempV.push_back(j + 1);
                tp += a[j][0];
                tf += a[j][1];
                ts += a[j][2];
                tv += a[j][3];
                totalPrice += a[j][4];
            }
        }

        if (tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
            if (retPrice >= totalPrice) {
                retPrice = totalPrice;
                retMap[retPrice].push_back(tempV);
            }
        }
    }

    if (retPrice == INT_MAX)
        cout << "-1";
    else {
        sort(retMap[retPrice].begin(), retMap[retPrice].end());
        cout << retPrice << '\n';
        for (int a : retMap[retPrice][0]) cout << a << " ";
    }
}