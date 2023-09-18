#include <bits/stdc++.h>
using namespace std;

int t;
string s;
stack<char> st;

bool yesOrNo(string s) {
    while(!st.empty()) st.pop();
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else if(!st.empty() && s[i] == ')' && st.top() == '(') {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> s;
        if(yesOrNo(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}