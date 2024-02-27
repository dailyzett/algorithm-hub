#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int value;
            cin >> value;
            st.push(value);
        } else if (temp == 2) {
            if (st.empty())
                cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (temp == 3) {
            cout << st.size() << '\n';
        } else if (temp == 4) {
            if (st.empty()) {
                cout << 1 << '\n';
            } else
                cout << 0 << '\n';
        } else if (temp == 5) {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
            }
        }
    }
    return 0;
}