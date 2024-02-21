#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> a;
vector<int> rotates;

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
    int t, k;
    cin >> t;
    a.resize(t);
    rotates.resize(t);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 8; j++) {
            char input;
            cin >> input;
            a[i].push_back(input);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int topCnt, dir;
        cin >> topCnt >> dir;

        topCnt--;
        // 현재 자석을 회전 시키는 방향 설정
        rotates[topCnt] = dir;

        // 왼쪽 자석들을 확인하고 회전 방향 설정
        int prevDir = dir;
        for (int j = topCnt - 1; j >= 0; j--) {
            if(a[j][2] != a[j + 1][6]) {
                prevDir *= -1;
                rotates[j] = prevDir;
            } else break;
        }
        // 오른쪽 자석들을 확인하고 회전 방향 설정
        prevDir = dir;
        for (int j = topCnt + 1; j < t; j++) {
            if(a[j - 1][2] != a[j][6]) {
                prevDir *= -1;
                rotates[j] = prevDir;
            } else break;
        }
        rotateAll();
        fill(rotates.begin(), rotates.end(), 0); // rotates 초기화
    }

    int ret = 0;
    for (int i = 0; i < t; i++) {
        if (a[i][0] == '1') ret++;
    }

    cout << ret << '\n';
    return 0;
}