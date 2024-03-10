#include <bits/stdc++.h>
using namespace std;

int cnt[1001], prev_list[1001], input[1001];
int n, ret=1, idx;
vector<int> ts;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    fill(cnt, cnt + 1001, 1);
    fill(prev_list, prev_list + 1001, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    cout << ret << '\n';
    int i = idx;
    for (; prev_list[i] != -1; i = prev_list[i]) {
        ts.push_back(input[i]);
    }
    ts.push_back(input[i]);
    for (int i = ts.size() - 1; i >= 0; i--) {
        cout << ts[i] << ' ';
    }
    return 0;
}