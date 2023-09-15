#include <bits/stdc++.h>
using namespace std;

/**
 *
 */

int n;
int one;
string s, prevValue;
int aScore, bScore;
int aSum, bSum;

int changeToInt(string a)
{
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int &sum, string s)
{
    sum += (changeToInt(s) - changeToInt(prevValue));
}

string printTime(int z)
{
    int hour = z / 60;
    int minutes = z % 60;
    string s1 = "00" + to_string(hour);
    string s2 = "00" + to_string(minutes);
    return s1.substr(s1.size() - 2, 2) + ":" + s2.substr(s2.size() - 2, 2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> one >> s;
        if (aScore > bScore)
            go(aSum, s);
        else if (bScore > aScore)
            go(bSum, s);
        if (one == 1)
            aScore++;
        else
            bScore++;
        prevValue = s;
    }
    if (aScore > bScore)
        go(aSum, "48:00");
    if (aScore < bScore)
        go(bSum, "48:00");

    cout << printTime(aSum) << '\n';
    cout << printTime(bSum) << '\n';
}