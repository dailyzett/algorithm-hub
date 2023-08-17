#include <bits/stdc++.h>
using namespace std;

int n, ret;
typedef long long ll;

int main() {
    while(scanf("%d", &n) != EOF) {
        ll cnt = 1;
        ret = 1;
        while(true) {
            if (cnt % n == 0) {
                cout << ret << '\n';
                break;
            }else {
                cnt = (cnt * 10) + 1; 
                cnt %= n;
                ret++;
            }
        }
    }
}