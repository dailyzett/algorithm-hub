#include <bits/stdc++.h>
using namespace std;

int n;
double ret;

int main() {
    cin >> n;
    vector<double> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double init = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i] * init)
            init = a[i];
        else
            init *= a[i];
        ret = max(ret, init);
    }

    printf("%.3lf", ret + 0.00001);
}