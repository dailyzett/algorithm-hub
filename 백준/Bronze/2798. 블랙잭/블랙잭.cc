#include <bits/stdc++.h>
using namespace std;

vector<int> cards;
int n, m;
int mv = INT_MIN;

void combi(int start, vector<int> b) {
    if (b.size() == 3) {
        int sum = 0;
        for (int i : b) sum += cards[i];
        if (sum <= m) {
            mv = max(mv, sum);
        }
        return;
    }

    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    cin >> n >> m;

    int cardNumber = 0;
    for (int i = 0; i < n; i++) {
        cin >> cardNumber;
        cards.push_back(cardNumber);
    }

    vector<int> b;
    combi(-1, b);

    cout << mv << '\n';
}