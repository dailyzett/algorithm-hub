#include <bits/stdc++.h>
using namespace std;

int t, n, m;

bool check(int temp, vector<int> &v) {
    int low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (temp == v[mid])
            return true;
        else if (v[mid] > temp)
            high = mid - 1;
        else if (v[mid] < temp)
            low = mid + 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        sort(v.begin(), v.end());
        cin >> m;
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            if (check(temp, v))
                cout << '1' << '\n';
            else
                cout << '0' << '\n';
        }
    }
    return 0;
}