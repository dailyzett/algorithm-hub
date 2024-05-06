#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b;
    cin >> T;  // 테스트 케이스의 수
    while (T--) {
        cin >> a >> b;
        vector<int> cycle;

        // 거듭제곱의 마지막 자릿수 패턴을 구함
        int current = a % 10;  // 처음 시작 숫자
        while (true) {
            if (find(cycle.begin(), cycle.end(), current) != cycle.end()) {
                break;  // 이미 패턴이 시작된 경우 중단
            }
            cycle.push_back(current);
            current = (current * a) % 10;
        }

        // b번째 거듭제곱의 마지막 자릿수는 cycle[(b-1) % cycle.size()]에 저장됨
        int result = cycle[(b - 1) % cycle.size()];
        if (result == 0) {
            cout << 10 << endl;  // 0인 경우 10번 컴퓨터에서 처리한 것으로 간주
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
