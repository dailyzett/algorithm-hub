#include <bits/stdc++.h>
using namespace std;

int main() {
    bool isFactor = false;
    bool isMultiple = false;

    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        if (b % a == 0) isFactor = true;
        if (a % b == 0) isMultiple = true;

        if (isFactor) cout << "factor" << '\n';
        if (isMultiple) cout << "multiple" << '\n';
        if (!isFactor && !isMultiple) cout << "neither" << '\n';

        isFactor = false;
        isMultiple = false;
    }
}