#include <cstring>
#include <iostream>
using namespace std;
const int N = 10;
char str[N][N];
int n, m, t;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
bool st[N][N];
bool res;
int x1, x2, x3, x4;
void dfs(int x, int y, int cnt)
{
    
    if(res || abs(x-x1)+abs(y-x2) > t - cnt) return;
    if(cnt == t)
    {
        if(str[x][y] == 'D') res = true;
        return;
    }
    st[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(!st[tx][ty] && tx >= 1 && tx <= n && ty >= 1 && ty <= m && str[tx][ty] != 'X')
        {
            st[tx][ty] = true;
            dfs(tx, ty, cnt+1);
            st[tx][ty] = false;
        }
    }
    
}

int main()
{
    while (1)
    {
        memset(st, 0, sizeof(st));
        memset(str, 0, sizeof(str));
        res = false;
        cin >> n >> m >> t;
        if(n == 0) break;
        for(int i=1;i<=n;i++) scanf("%s", str[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(str[i][j] == 'D') x1 = i, x2 = j;
                else if(str[i][j] == 'S') x3 = i, x4 = j;
        if((abs(x3 - x1) + abs(x4 - x2) + t) % 2 != 0) res = false;//一奇一偶必不能到达
        else dfs(x3, x4, 0);

        if(res) puts("YES");
        else puts("NO");
    }
    
    return 0;
}