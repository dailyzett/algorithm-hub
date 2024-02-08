#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
int mul[101], visited[101];
vector<int> v;
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> mul[i];
    }

    for (int i = 0; i < k; i++) {
        if (!visited[mul[i]]) {
            if (v.size() == n) {
                int last_index = 0;
                int pos = 0;
                for (int m : v) {
                    int here_index = INT_MAX;
                    for (int j = i + 1; j < k; j++) {
                        if (m == mul[j]) {
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
                ret++;
                v.erase(find(v.begin(), v.end(), pos));
            }

            v.push_back(mul[i]);
            visited[mul[i]] = 1;
        }
    }

    cout << ret << '\n';
}