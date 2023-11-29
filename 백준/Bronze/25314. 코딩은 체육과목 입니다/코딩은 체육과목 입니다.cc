#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    int iter = n / 4;
    for (int i = 0; i < iter; i++) {
        cout << "long ";
    }
    cout << "int";
}