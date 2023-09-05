#include <bits/stdc++.h>
using namespace std;

int n, m;
int j, l, r;
int a[12][12];
int temp;
int ret;

int main()
{
    cin >> n >> m >> j;

    int l = 1;

    for (int i = 0; i < j; i++)
    {
        int r = l + m - 1;
        cin >> temp;
        if(temp >= l && temp <= r) continue;
        if(temp < l) {
            ret += (l-temp);
            l = temp;
        } else {
            l += (temp - r);
            ret += (temp - r);
        }
    }

    cout << ret << '\n';
    return 0;
}