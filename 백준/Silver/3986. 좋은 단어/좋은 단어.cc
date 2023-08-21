#include <bits/stdc++.h>
using namespace std;

int n;
int ret;

bool isGoodNumber(string s) {
    stack<char> st;
    for(char c: s) {
        if(st.size() && st.top() == c) st.pop();
        else st.push(c);
    }

    if(st.size() == 0) return true;
    else return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(isGoodNumber(s)) ret++;
    }

    cout << ret << '\n';
    return 0;
}