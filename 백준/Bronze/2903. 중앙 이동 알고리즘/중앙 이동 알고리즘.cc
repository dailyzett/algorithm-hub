#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int init_number = 2;

    int i = 0;
    while (true) {
        init_number += pow(2, i);
        i++;
        if (pow(2, i) >= pow(2, n)) break;
    }

    cout << init_number * init_number << '\n';
}