#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main() {
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        else {
            int maxValue = max(max(a, b), c);
            if ((a + b <= maxValue) || (b + c <= maxValue) || (a + c <= maxValue))
                cout << "Invalid" << '\n';
            else if (a == b && b == c && c == a)
                cout << "Equilateral" << '\n';
            else if (a != b && b != c && c != a)
                cout << "Scalene" << '\n';
            else if (a == b || b == c || c == a)
                cout << "Isosceles" << '\n';
        }
    }

    return 0;
}