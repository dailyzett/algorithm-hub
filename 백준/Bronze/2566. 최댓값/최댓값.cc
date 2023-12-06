#include <bits/stdc++.h>
using namespace std;

int a[9][9];
int maxValue = INT_MIN;
int maxI, maxJ;  // 최댓값의 위치를 저장할 변수

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if (a[i][j] > maxValue) {
                maxValue = a[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    cout << maxValue << '\n';                     // 최댓값 출력
    cout << maxI + 1 << ' ' << maxJ + 1 << '\n';  // 위치 출력 (1-indexed)
}