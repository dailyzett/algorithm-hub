#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isGroupWord(const string& word) {
    vector<bool> seen(26, false);
    char last = '\0';

    for (char ch : word) {
        if (last != ch) {
            if (seen[ch - 'a']) return false;
            seen[ch - 'a'] = true;
            last = ch;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if (isGroupWord(word)) count++;
    }

    cout << count << endl;
    return 0;
}
