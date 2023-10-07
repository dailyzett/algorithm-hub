#include <bits/stdc++.h>
using namespace std;

const int V = 1000001;
int n, a[V], ret[V];
stack<int> st;

int main() {
    memset(ret, -1, sizeof(ret));
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        while(st.size() && a[st.top()] < a[i]) {
            ret[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0; i<n; i++) {
        cout << ret[i] << ' ';
    }
}