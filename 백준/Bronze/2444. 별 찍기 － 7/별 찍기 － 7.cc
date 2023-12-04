#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 상단 부분 (1부터 N까지)
    for (int i = 1; i <= N; i++) {
        // 공백 출력
        for (int j = 0; j < N - i; j++) {
            cout << " ";
        }
        // 별 출력
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    // 하단 부분 (N-1부터 1까지)
    for (int i = N - 1; i > 0; i--) {
        // 공백 출력
        for (int j = 0; j < N - i; j++) {
            cout << " ";
        }
        // 별 출력
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
