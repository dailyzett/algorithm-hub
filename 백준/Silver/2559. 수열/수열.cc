#include <bits/stdc++.h>
using namespace std;

int n, k;
int ret = INT_MIN;

int main() {
    cin >> n;
    cin >> k;

    int arr[n];
    vector<int> psum;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int m = 0;
    for(int i=0; i+k <= n; i++) {
        if(i == 0) {
            for(int i = 0; i < k; i++) {
                m += arr[i];
            }
            psum.push_back(m);
        } else {
            m = m - arr[i-1] + arr[i+k-1];
            psum.push_back(m);
        }
    }
    
    for(int i:psum) ret = max(ret, i);
    cout << ret;
}