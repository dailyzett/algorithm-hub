#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    
    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

vector<string> solution(vector<string> record) {
    vector<string> ret;
    map<string, string> mp;
    for(const string &r: record) {
        vector<string> temp = split(r, ' ');
        string keyword = temp[0];
        string userId = temp[1];
        if(temp.size() > 2) {
            string username = temp[2];
            mp[userId] = username;
        }
    }
    
    for(const string &r: record) {
        vector<string> temp = split(r, ' ');
        string keyword = temp[0];
        string userId = temp[1];
        string message;
        
        if(keyword == "Enter") {
            message = mp[userId] + "님이 들어왔습니다.";
        } else if(keyword == "Leave") {
            message = mp[userId] + "님이 나갔습니다.";
        } else {
            continue;
        }
        
        ret.push_back(message);
    }
    return ret;
}