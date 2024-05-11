#include <bits/stdc++.h>
using namespace std;

int t, n;

void go(int num) {
    vector<string> pub1(num), pub2(num), enc(num), dec(num);
    map<string, int> mp;

    // 첫번째 공개키
    for (int i = 0; i < num; i++) {
        cin >> pub1[i];
    }

    // 두번째 공개키
    for (int i = 0; i < num; i++) {
        cin >> pub2[i];
        mp[pub2[i]] = i;
    }

    // 암호화된 메시지 입력
    for (int i = 0; i < num; i++) {
        cin >> enc[i];
    }

    for (int i = 0; i < num; i++) {
        int pos = mp[pub1[i]];
        dec[i] = enc[pos];
    }

    for (int i = 0; i < num; i++) {
        cout << dec[i] << " ";
    }
    cout << '\n';
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        go(n);
    }
    return 0;
}