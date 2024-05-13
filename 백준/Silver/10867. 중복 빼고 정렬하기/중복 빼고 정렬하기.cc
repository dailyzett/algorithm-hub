#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert(num);
    }

    for (int num : st) {
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for (int num : v) {
        cout << num << ' ';
    }
    return 0;
}