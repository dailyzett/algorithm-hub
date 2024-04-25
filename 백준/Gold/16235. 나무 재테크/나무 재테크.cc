#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[11][11];
int yang[11][11];
vector<int> tree[11][11];
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring_summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tree[i][j].size() == 0) continue;
            int die_tree = 0;
            sort(tree[i][j].begin(), tree[i][j].end());
            vector<int> temp_tree;
            for (int t : tree[i][j]) {
                if (yang[i][j] >= t) {
                    yang[i][j] -= t;
                    temp_tree.push_back(t + 1);
                } else {
                    die_tree += t / 2;
                }
            }

            tree[i][j] = temp_tree;
            yang[i][j] += die_tree;
        }
    }
}
void fall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tree[i][j].size() == 0) continue;
            for (int t : tree[i][j]) {
                if (t % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            yang[i][j] += A[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> k;
    fill(&yang[0][0], &yang[0][0] + 11 * 11, 5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        tree[x][y].push_back(z);
    }

    for (int i = 0; i < k; i++) {
        spring_summer();
        fall();
        winter();
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += tree[i][j].size();
        }
    }

    cout << ret << '\n';
    return 0;
}