#include <bits/stdc++.h>
using namespace std;

/**
 * [Hint] 팩토리얼의 0의 개수는 10이 얼마나 있느냐에 따라 갈린다.
 * 10은 2*5 이다. 즉 2,5 가 얼마나 많이 있는지 개수를 세면 된다.
 * 개수를 셀 때 2나 5의 제곱만큼 나눈 숫자 중의 최소값을 리턴한다.
 */

int t, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int ret2 = 0, ret5 = 0;
        for (int j = 2; j <= n; j *= 2)
        {
            ret2 += n / j;
        }

        for (int j = 5; j <= n; j *= 5)
        {
            ret5 += n / j;
        }
        cout << min(ret2, ret5) << '\n';
    }
    return 0;
}