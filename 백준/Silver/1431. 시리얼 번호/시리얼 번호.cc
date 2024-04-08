#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

int getSum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            sum += s[i] - '0';
        }
    }
    return sum;
}

bool compareFunction(string s1, string s2) {
    if (s1.length() < s2.length())
        return true;
    else if (s1.length() == s2.length()) {
        int sum1 = getSum(s1);
        int sum2 = getSum(s2);
        if (sum1 < sum2)
            return true;
        else if (sum1 == sum2 && s1 < s2)
            return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), compareFunction);
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
}