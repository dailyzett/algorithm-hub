#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int maxRet = INT_MIN;
int minRet = INT_MAX;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        minRet = min(minRet, temp);
        maxRet = max(maxRet, temp);
    }
    cout << minRet << " " << maxRet;
    return 0;
}