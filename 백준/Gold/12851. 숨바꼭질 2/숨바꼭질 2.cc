#include <bits/stdc++.h>
using namespace std;

int n, k, retSeconds, retCounts;
const int MAX_VALUE = 100000;
int visited[MAX_VALUE + 1], cnt[MAX_VALUE + 1];

int main() {
    cin >> n >> k;
    if(n == k) {
        cout << "0" << '\n' << "1" << '\n';
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(q.size()) {
        int here = q.front();
        q.pop();
        int arr[3] = {here -1, here + 1, here * 2};
        for(int i=0; i<3; i++) {
            if(0 <= arr[i] && arr[i] <= MAX_VALUE) {
                if(visited[arr[i]] == 0) {
                    q.push(arr[i]);
                    visited[arr[i]] = visited[here] + 1;
                    cnt[arr[i]] += cnt[here];
                } else if (visited[arr[i]] == visited[here] + 1){
                    cnt[arr[i]] += cnt[here];
                } else {
                    continue;
                }
            }
        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
}