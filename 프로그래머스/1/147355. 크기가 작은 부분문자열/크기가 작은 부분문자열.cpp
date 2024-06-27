#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    vector<string> v;
    
    for(int i=0; i<t.size() - p.size() + 1; i++) {
        string s = t.substr(i, p.size());
        v.push_back(s);
    }
    
    int count = 0;
    for(string s : v) {
        try {
        long long num = stoll(s);
        if(num <= stoll(p)) count++;
        } catch(const out_of_range& e) {
            continue;
        }
    }
    
    return count;
}