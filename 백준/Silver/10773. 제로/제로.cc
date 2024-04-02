#include <bits/stdc++.h>
using namespace std;

int k, a;
stack<int> stk;
int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a;
        if (a != 0) stk.push(a);
        if (a == 0) stk.pop();
    }

    int ret = 0;
    while (!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }

    cout << ret << '\n';
}