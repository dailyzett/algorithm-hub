#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimeter) {
    vector<string> ret;
    long long pos;
    string token = "";
    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}

vector<string> v;
vector<double> vi;
double totalHak = 0;
int main() {
    for (int i = 0; i < 20; i++) {
        string s;
        getline(cin, s);
        v = split(s, " ");
        if (v[2] == "P") continue;

        double hak = stod(v[1]);
        totalHak += hak;

        if (v[2] == "A+")
            vi.push_back(hak * 4.5);
        else if (v[2] == "A0")
            vi.push_back(hak * 4.0);
        else if (v[2] == "B+")
            vi.push_back(hak * 3.5);
        else if (v[2] == "B0")
            vi.push_back(hak * 3.0);
        else if (v[2] == "C+")
            vi.push_back(hak * 2.5);
        else if (v[2] == "C0")
            vi.push_back(hak * 2.0);
        else if (v[2] == "D+")
            vi.push_back(hak * 1.5);
        else if (v[2] == "D0")
            vi.push_back(hak * 1.0);
        else if (v[2] == "F")
            vi.push_back(hak * 0.0);
    }

    double sum = 0;
    for (double i : vi) {
        sum += i;
    }

    cout << sum / totalHak << '\n';

    return 0;
}