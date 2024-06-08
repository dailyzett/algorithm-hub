#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
string s;
vector<string> vs;
unordered_map<ll, queue<ll>> mp;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vs.push_back(s);
    }

    ll counter = 0;
    for (int i = 0; i < vs.size(); i++) {
        int len = vs[i].size();

        if (i > k) {
            int len = vs[i - k - 1].size();
            mp[len].pop();
        }

        counter += mp[len].size();
        mp[len].push(i);
    }
    cout << counter << '\n';
    return 0;
}