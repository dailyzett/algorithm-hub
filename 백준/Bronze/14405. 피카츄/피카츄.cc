#include <bits/stdc++.h>
using namespace std;

string a[] = {"pi", "ka", "chu"};
int main() {
    string s;
    getline(cin, s);

    while (!s.empty()) {
        bool isPattern = false;
        for (int i = 0; i < 3; i++) {
            if (s.find(a[i]) == 0) {
                s = s.substr(a[i].size());
                isPattern = true;
                break;
            }
        }

        if (!isPattern) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}