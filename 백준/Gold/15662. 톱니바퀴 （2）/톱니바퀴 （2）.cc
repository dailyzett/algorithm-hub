#include <bits/stdc++.h>
using namespace std;

// 반시계 방향: rotate(a[0].begin(), a[0].begin() + 1, a[0].end());
// 시계 방향: rotate(a[0].rbegin(), a[0].rbegin() + 1, a[0].rend());
// -1이 반시계, 1이 시계

vector<vector<char>> a;
vector<int> rotates;

int t, k;
char input;

void rotateAll() {
    for (int i = 0; i < rotates.size(); i++) {
        if (rotates[i] == -1) {
            rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
        } else if (rotates[i] == 1) {
            rotate(a[i].rbegin(), a[i].rbegin() + 1, a[i].rend());
        }
    }
}

int main() {
    cin >> t;
    a.resize(t);
    rotates.resize(t);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> input;
            a[i].push_back(input);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int topCnt, dir;
        cin >> topCnt >> dir;

        topCnt--;
        rotates[topCnt] = dir;

        int prevDir = dir;
        for (int j = topCnt - 1; j >= 0; j--) {
            if (a[j][2] != a[j + 1][6]) {
                prevDir *= -1;
                rotates[j] = prevDir;
            } else break;
        }

        prevDir = dir;
        for (int j = topCnt + 1; j < t; j++) {
            if (a[j - 1][2] != a[j][6]) {
                prevDir *= -1;
                rotates[j] = prevDir;
            } else break;
        }
        rotateAll();
        fill(rotates.begin(), rotates.end(), 0);
    }

    int ret = 0;
    for (int i = 0; i < t; i++) {
        if (a[i][0] == '1') ret++;
    }

    cout << ret << '\n';
    return 0;
}