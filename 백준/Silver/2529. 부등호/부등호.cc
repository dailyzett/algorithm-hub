
#include <bits/stdc++.h>
using namespace std;

int k;
char c[13];
int visited[13];
vector<string> ret;

bool isCompare(char op, char num1, char num2) {
    if (op == '>' && num1 > num2) return true;
    if (op == '<' && num1 < num2) return true;
    return false;
}

void go(int idx, string s) {
    if (idx == k + 1) {
        ret.push_back(s);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i]) continue;
        if (idx == 0 || isCompare(c[idx - 1], s[idx - 1] - '0', i)) {
            visited[i] = 1;
            go(idx + 1, s + to_string(i));
            visited[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }

    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n' << ret[0] << '\n';
    return 0;
}