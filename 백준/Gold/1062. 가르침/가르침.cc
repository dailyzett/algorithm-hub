#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> words;

int count(int learned) {
    int cnt = 0;
    for (int word : words) {
        if ((word & learned) == word) cnt++;
    }
    return cnt;
}

int go(int idx, int k, int learned) {
    if (k < 0) return 0;
    if (idx == 26) return count(learned);
    int ret = go(idx + 1, k - 1, learned | (1 << idx));
    if (idx != 'a' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a' && idx != 'n' - 'a') {
        ret = max(ret, (go(idx + 1, k, learned)));
    }
    return ret;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int temp = 0;
        for (char ch : s) {
            temp |= (1 << (ch - 'a'));
        }
        words.push_back(temp);
    }
    cout << go(0, k, 0) << '\n';
}
