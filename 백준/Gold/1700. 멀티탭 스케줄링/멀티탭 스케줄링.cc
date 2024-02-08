#include <bits/stdc++.h>
using namespace std;

int n, k, multitab[104], visited[104], cnt;
vector<int> v;
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> multitab[i];
    }

    for (int i = 0; i < k; i++) {
        if (!visited[multitab[i]]) {
            if (v.size() == n) {
                int last_index = 0, pos;
                for (int m : v) {
                    int here_index = INT_MAX;
                    for (int j = i + 1; j < k; j++) {
                        if (m == multitab[j]) {
                            here_index = j;
                            break;
                        }
                    }

                    if (last_index < here_index) {
                        last_index = here_index;
                        pos = m;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }

            v.push_back(multitab[i]);
            visited[multitab[i]] = 1;
        }
    }
    cout << cnt << '\n';
}