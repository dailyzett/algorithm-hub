#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    string result = "";

    while (n > 0) {
        int num = n % b;

        if (num >= 10) {
            result += (char)(num + 'A' - 10);
        } else {
            result += to_string(num);
        }
        n /= b;
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
}