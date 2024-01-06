#include <iostream>
#include <vector>

using namespace std;

// 체스판의 각 색깔을 B 와 W 를 사용하여 표현
char BW[2] = {'B', 'W'};

int checkMinChange(vector<string>& board, int x, int y) {
    // 두 가지 경우를 고려하므로, 각각에 대한 결과를 저장할 변수 선언
    int ret[2] = {0, 0};

    for (int b = 0; b < 2; b++) {
        for (int i = x; i < x + 8; i++) {
            for (int j = y; j < y + 8; j++) {
                // 현재 칸의 색이 맞지 않으면 해당 경우의 결과값 증가
                if (board[i][j] != BW[(i + j + b) % 2]) {
                    ret[b]++;
                }
            }
        }
    }
    // 두 경우 중 더 작은 값을 반환
    return min(ret[0], ret[1]);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int answer = 8*8;
    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            answer = min(answer, checkMinChange(board, i, j));
        }
    }

    cout << answer << '\n';
    
    return 0;
}