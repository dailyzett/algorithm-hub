#include <bits/stdc++.h>
using namespace std;

int n;
int m = -1;
vector<int> v;
vector<double> v2;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        m = max(m, temp);
        v.push_back(temp);
    }

    for (int i : v) {
        double result = (static_cast<double>(i) / m) * 100;
        v2.push_back(result);
    }

    double sum = 0.0;
    for (double i : v2) {
        sum += i;
    }
    double average = sum / n;
    cout << average << '\n';
}