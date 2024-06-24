#include <bits/stdc++.h>

using namespace std;

int max_y, max_x;

vector<string> split(const string& str, char delimeter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    
    while(getline(ss, token, delimeter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

bool isPass(int y, int x, const vector<vector<char>>& board) {
    if(y < 0 || x < 0 || y >= max_y || x >= max_x) return false;
    if(board[y][x] == 'X') return false;
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<char>> board(park.size(), vector<char>(park[0].size(), 0));
    max_y = park.size();
    max_x = park[0].size();
    
    int sy=0;
    int sx=0;
    
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            board[i][j] = park[i][j];
            if(board[i][j] == 'S') {
               sy = i; sx = j;
            }        
        }
    }
    
    for(string route: routes) {
        vector<string> word = split(route, ' ');
        string dir = word[0];
        int dis = stoi(word[1]);
        
        int ny = sy;
        int nx = sx;

        bool valid = true;
        for(int i = 0; i < dis; i++) {
            if (dir == "E") {
                nx += 1;
            } else if (dir == "W") {
                nx -= 1;
            } else if (dir == "N") {
                ny -= 1;
            } else if (dir == "S") {
                ny += 1;
            }
            
            if(!isPass(ny, nx, board)) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            sy = ny;
            sx = nx;
        }
    }
    
    answer.push_back(sy);
    answer.push_back(sx);
    return answer;
}