#include <bits/stdc++.h>
using namespace std;

int t, m, n;
vector<int> nv;
vector<int> mv;

bool check(vector<int> &v, int num) {
    int left = 0;
    int right = v.size() - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (v[mid] == num) return true;

        if (v[mid] < num) {
            left = mid + 1;
        } else if (v[mid] > num) {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        nv.clear();
        mv.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            nv.push_back(input);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int input;
            cin >> input;
            mv.push_back(input);
        }

        sort(nv.begin(), nv.end());

        for (int i = 0; i < m; i++) {
            if (check(nv, mv[i]))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}