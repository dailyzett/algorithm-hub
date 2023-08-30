#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n;
int a[max_n][max_n];
int maxHeight = 1;
bool water[max_n][max_n];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret = 0;
int maxRet = 1;

void dfs(int y, int x, int h)
{
    water[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || water[ny][nx] == true)
            continue;
        if(a[ny][nx] > h) dfs(ny, nx, h);
    }
    return;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            maxHeight = max(a[i][j], maxHeight);
        }
    }

    for (int h = 1; h <= maxHeight; h++)
    {
        fill(&water[0][0], &water[0][0] + sizeof(water)/sizeof(water[0][0]), false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] <= h) water[i][j] = true;
                
            }
        }

        ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(water[i][j] == false && a[i][j] > h) {
                    dfs(i, j, h);
                    ret++;
                }
            }
        }

        maxRet = max(maxRet, ret);
    }

    cout << maxRet << '\n';
}