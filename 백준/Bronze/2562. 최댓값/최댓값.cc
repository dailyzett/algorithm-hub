#include <bits/stdc++.h>
using namespace std;

int maxRet = INT_MIN;
vector<int> v;
int main() {
    for (int i = 0; i < 9; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    auto maxRet = max_element(v.begin(), v.end());

    int maxIndex = 0;
    if (maxRet != v.end()) {
        maxIndex = distance(v.begin(), maxRet);
    }
    cout << *maxRet << '\n';
    cout << maxIndex + 1 << '\n';
}