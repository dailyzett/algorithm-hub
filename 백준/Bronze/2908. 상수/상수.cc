#include <bits/stdc++.h>
using namespace std;

string a, b;
int main() {
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << max(stoi(a), stoi(b)) << '\n';
}