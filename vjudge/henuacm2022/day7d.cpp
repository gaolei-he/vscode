#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
typedef pair<int, int> PII;
const int N = 25;
char str[N][N];
bool st[N][N];
int ans = 0;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
bool res = false;
void bfs()
{
    queue<PII> q;
    int x, y;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(str[i][j] == 'S') x = i, y = j;
    q.push({x, y});
    st[x][y] = true;
    while (q.size())
    {
        ans ++;
        queue<PII> tmp;
        while (q.size())
        {
            PII t = q.front();
            q.pop();
            bool flag = false;
            bool flag1 = false;
            for (int i = 0; i < 4; i++)
            {
                flag = false;
                int tx = dx[i] + t.first, ty = dy[i] + t.second;
                if(tx < 1 || tx > m || ty < 1 || ty > n || st[tx][ty]) continue;
                if(str[tx][ty] == 'T') return;
                if(str[tx][ty] == '.' || str[tx][ty] == 'T')
                {
                    tmp.push({tx, ty});
                    st[tx][ty] = true;
                }
                else if(str[tx][ty] == '|' || str[tx][ty] == '-')
                {
                    
                    if(ans&1 && (i==0||i==2) && str[tx][ty] == '|') flag = true;
                    if(!(ans&1) && (i==0||i==2) && str[tx][ty] == '-') flag = true;
                    if(ans&1 && (i==1||i==3) && str[tx][ty] == '-') flag = true;
                    if(!(ans&1) && (i==1||i==3) && str[tx][ty] == '|') flag = true;
                    if(flag) flag1 = true;
                    if(flag) continue;
                    switch (i)
                    {
                    case 0:
                        if(str[tx][ty-1] == 'T') return;
                        if((str[tx][ty-1] == '.' || str[tx][ty-1] == 'T') && !st[tx][ty-1]) tmp.push({tx, ty-1});
                        st[tx][ty-1] = true;
                        break;
                    case 1:
                        if(str[tx-1][ty] == 'T') return;
                        if((str[tx-1][ty] == '.' || str[tx-1][ty] == 'T') && !st[tx-1][ty]) tmp.push({tx-1, ty});
                        st[tx-1][ty] = true;
                        break;
                    case 2:
                        if(str[tx][ty+1] == 'T') return;
                        if((str[tx][ty+1] == '.' || str[tx][ty+1] == 'T') && !st[tx][ty+1]) tmp.push({tx, ty+1});
                        st[tx][ty+1] = true;
                        break;
                    case 3:
                        if(str[tx+1][ty] == 'T') return;
                        if((str[tx+1][ty] == '.' || str[tx+1][ty] == 'T') && !st[tx+1][ty]) tmp.push({tx+1, ty});
                        st[tx+1][ty] = true;
                        break;
                    default:
                        break;
                    }
                }

            }
            if(flag1) tmp.push({t.first, t.second});
        }
        if(res) break;
        q = tmp;
    }
    
}

int main()
{
    while (cin >> m)
    {
        memset(str, 0, sizeof(str));
        memset(st, 0, sizeof(st));
        cin >> n;
        for(int i=1;i<=m;i++) scanf("%s", str[i] + 1);
        bfs();
        cout << ans << endl;
        ans = 0;
        res = false;
    }
    
    return 0;
}
