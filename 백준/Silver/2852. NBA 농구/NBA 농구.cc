#include <bits/stdc++.h>
using namespace std;

int n, o;
string s, pre;
int aScore, bScore;
int aSum, bSum;

int changeToInt(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3,2).c_str());
}

void go(int &sum, string s) {
    sum += (changeToInt(s) - changeToInt(pre));
}

string printTime(int i) {
    string hour = "00" + to_string(i / 60);
    string minutes = "00" + to_string(i%60);
    return hour.substr(hour.size() - 2, 2) + ":" + minutes.substr(minutes.size() - 2, 2);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> o >> s;
        if(aScore > bScore) go(aSum, s);
        else if(aScore < bScore) go(bSum, s);
        if(o == 1) aScore++;
        else bScore++;
        pre = s;
    }
    if(aScore > bScore) go(aSum, "48:00");
    else if(aScore < bScore) go(bSum, "48:00");

    cout << printTime(aSum) << '\n';
    cout << printTime(bSum) << '\n';
}