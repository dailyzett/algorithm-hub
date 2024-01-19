#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string> inOffice; // Using a set to store the names of people in the office
    for (int i = 0; i < n; ++i) {
        string name, status;
        cin >> name >> status;

        if (status == "enter") {
            inOffice.insert(name);
        } else {
            inOffice.erase(name);
        }
    }

    // The names will be in reverse order because set in C++ is ordered in ascending order by default
    for (auto it = inOffice.rbegin(); it != inOffice.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}
