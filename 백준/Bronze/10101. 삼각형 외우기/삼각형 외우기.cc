#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // sum의 값을 먼저 계산합니다.
    int sum = a + b + c;

    if (sum != 180) {
        cout << "Error" << '\n';
    } else if (a == b && b == c) {
        cout << "Equilateral" << '\n';
    } else if (a == b || b == c || c == a) {
        cout << "Isosceles" << '\n';
    } else {
        cout << "Scalene" << '\n';
    }

    return 0;
}