#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int main() {
    cin >> n >> m >> t;
    vector<int> distances;
    for (int i = 0; i < t + 1; i++) {
        int dir, dis;
        cin >> dir >> dis;

        int coord;
        switch (dir) {
            case 1:
                coord = dis;
                break;
            case 2:
                coord = 2 * n + m - dis;
                break;
            case 3:
                coord = 2 * (n + m) - dis;
                break;
            case 4:
                coord = n + dis;
                break;
        }
        distances.push_back(coord);
    }
    int guard = distances.back();
    distances.pop_back();

    int dule = 2 * (n + m);  // 둘레
    int ret = 0;
    for (int distance : distances) {
        int sub = abs(guard - distance);
        int sub2 = dule - sub;
        ret += min(sub, sub2);
    }
    cout << ret << '\n';
}