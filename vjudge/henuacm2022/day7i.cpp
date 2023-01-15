#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
char str[N][N];

void dfs(int x, int y)
{
    str[x][y] = '*';
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++)
    {
        if(str[dx[i]+x][dy[i]+y] == '@') dfs(x+dx[i], y+dy[i]);
    }
    
}

int main()
{
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(str, 0, sizeof(str));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str[i+1] + 1);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(str[i][j] == '@')
                {
                    dfs(i, j);
                    cnt ++;
                }
        cout << cnt << endl;
    }
    
    return 0;
}