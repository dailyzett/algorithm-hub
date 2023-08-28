#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[104][104];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int x, y;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++)
        {
            a[i][j] = input[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n-1][m-1] << '\n';
}