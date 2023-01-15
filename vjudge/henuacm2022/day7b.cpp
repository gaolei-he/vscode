#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
char str[N][N];
int n, m;
int ans = 0;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};


void dfs(int x, int y)
{
    str[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        int tx = dx[i] + x, ty = dy[i] + y;
        if(str[tx][ty] == 'W') dfs(tx, ty);
    }
    
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%s", str[i] + 1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        
            if(str[i][j] == 'W')
            {
                dfs(i, j);
                ans ++;
            }
    cout << ans << endl;
    return 0;
}