#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    istringstream iss(s);
    string word;
    int count = 0;
    while (iss >> word) {
        count++;
    }
    cout << count;
}