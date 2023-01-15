#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e3+10;
char str[N][N];
bool st[N][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int n, m;
int ans = 0;

void bfs()
{
    int x, y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j] == '@') x = i, y = j;
    queue<pair<int, int> > q;
    q.push({x, y});
    st[x][y] = true;
    while(q.size())
    {
        ans += q.size();
        queue<pair<int, int> > tmp;
        while(q.size())
        {
            pair<int, int> t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = t.first + dx[i], ty = t.second + dy[i];
                if(!st[tx][ty] && tx >=1 && tx <= n && ty >= 1 && ty <= m && str[tx][ty] == '.')
                {
                    st[tx][ty] = true;
                    tmp.push({tx, ty});
                }
            }
        }
        q = tmp;
    }
}

int main()
{
    while (1)
    {
        memset(st, 0, sizeof(st));
        scanf("%d %d", &m, &n);
        if(!n) break;
        for(int i=1;i<=n;i++) scanf("%s", str[i]+1);
        bfs();
        cout << ans << endl;
        ans = 0;
    }
    

    return 0;
}