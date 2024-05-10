#include <bits/stdc++.h>
using namespace std;

int main() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);

    cout << put_time(localtime(&now_c), "%Y-%m-%d") << '\n';
}