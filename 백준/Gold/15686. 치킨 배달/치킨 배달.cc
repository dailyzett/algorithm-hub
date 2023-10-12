#include <bits/stdc++.h>
using namespace std;

int n,m, result = INT_MAX;
int a[52][52];
vector<vector<int>> chickenDistanceList;
vector<pair<int, int>> homeList, chickenList;

void combi(int start, vector<int> v) {
    if(v.size() == m) {
        chickenDistanceList.push_back(v);
        return;
    }
    for(int i=start+1; i<chickenList.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) homeList.push_back({i, j});
            if(a[i][j] == 2) chickenList.push_back({i, j});
        }
    }

    vector<int> v;
    combi(-1, v);

    for(vector<int> cDList: chickenDistanceList) {
        int ret = 0;
        for(pair<int, int> home: homeList) {
            int minValue = INT_MAX;
            for(int ch: cDList) {
                int distance = abs(home.first - chickenList[ch].first) + abs(home.second - chickenList[ch].second);
                minValue = min(distance, minValue);
            }
            ret += minValue;
        }
        result = min(result, ret);
    }
    cout << result << '\n';
    return 0;
}