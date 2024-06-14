#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int go(int n, ll l, ll r) {
    if(n == 0) return 1;
    
    ll len = pow(5, n);
    ll section_len = len / 5;
    
    ll result = 0;
    for(ll i=0; i<5; i++) {
        ll start = i * section_len;
        ll end = (i+1) * section_len - 1;
        
        if(l > end || r < start) continue;
        if(i==2) continue;
        
        ll new_l = max(l, start) - start;
        ll new_r = min(r, end) - start;
        result += go(n-1, new_l, new_r);
    }
    return result;
}

int solution(int n, ll l, ll r) {
    return go(n, l-1, r-1);
}