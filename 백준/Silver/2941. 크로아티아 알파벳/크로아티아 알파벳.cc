#include <bits/stdc++.h>
using namespace std;

int main() {
    string a[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    cin >> s;

    for (string c : a) {
        while (s.find(c) != string::npos) {
            s.replace(s.find(c), c.length(), "@");
        }
    }

    cout << s.length() << '\n';
}