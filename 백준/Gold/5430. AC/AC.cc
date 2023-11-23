#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, s;
char delimiter = ',';

vector<int> extractNumbers(const string& s) {
    // 대괄호 제거
    string cleanedStr = s.substr(1, s.size() - 2);

    stringstream ss(cleanedStr);
    vector<int> nums;
    string token;
    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            int num = stoi(token);
            nums.push_back(num);
        }
    }
    return nums;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> p;
        cin >> n;
        cin.ignore();

        getline(cin, s);
        vector<int> nums = extractNumbers(s);
        bool isError = false;
        bool isReversed = false;
        int start = 0, end = n;

        for (char c : p) {
            if (c == 'R') {
                isReversed = !isReversed;
            } else if (c == 'D') {
                if (start >= end) {
                    isError = true;
                    break;
                }
                isReversed ? end-- : start++;
            }
        }

        if (isError)
            cout << "error" << '\n';
        else {
            cout << "[";
            for (int i = start; i < end; i++) {
                cout << nums[isReversed ? end - 1 - (i - start) : i];
                if (i < end - 1) cout << ",";
            }
            cout << "]\n";
        }
    }
}