#include <bits/stdc++.h>
using namespace std;

string input, boom;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input >> boom;
    stack<char> st;

    for (int i = 0; i < input.size(); i++) {
        st.push(input[i]);

        if (st.size() >= boom.size() && st.top() == boom[boom.size() - 1]) {
            string temp = "";
            for (char c : boom) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp != boom) {
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
    }

    if (st.empty()) {
        cout << "FRULA" << '\n';
    } else {
        string ret = "";
        while (st.size()) {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }

    return 0;
}