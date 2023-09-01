#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int m, n, k;
int a[101][101];
int square[101][101];
int lx, ly, rx, ry;
int num;
int area;
vector<int> v;

void dfs(int y, int x)
{
    square[y][x] = 1;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;
        if (square[ny][nx] == 0)
        {
            dfs(ny, nx);
        }
    }
    return;
}

int main()
{
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> lx >> ly >> rx >> ry;
        for(int x=lx; x<rx; x++) {
            for(int y=ly; y<ry; y++) {
                square[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (square[i][j] == 0)
            {
                dfs(i, j);
                num++;
                v.push_back(area);
                area = 0;
            }
            
        }
    }
    cout << num << '\n';
    sort(v.begin(), v.end());
    for(int i: v) cout << i << ' ';
    return 0;
}
