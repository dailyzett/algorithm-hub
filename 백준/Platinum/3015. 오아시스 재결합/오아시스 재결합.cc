#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, temp, ret;
stack<pair<ll, ll>> st;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int cnt = 1;
        while (st.size() && st.top().first <= temp) {
            ret += st.top().second;
            if (temp == st.top().first) {
                cnt = st.top().second + 1;
            } else {
                cnt = 1;
            }
            st.pop();
        }
        if (st.size()) ret++;
        st.push({temp, cnt});
    }
    cout << ret << '\n';
    return 0;
}