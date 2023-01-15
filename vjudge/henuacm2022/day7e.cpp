#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
char str[N][N];
int n, m, x, y;
int ans = 0;
bool st[N][N], mp[N][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int t = 6;
typedef pair<int, int> PII;
queue<PII> q, f;
void bfs()
{
    q.push({x, y});
    st[x][y] = true;
    while (q.size())
    {
        queue<PII> tmp;
        t --;
        if(!t)
        {
            ans = 1e9+10;
            return;
        }
        ans ++;
        while (q.size())
        {
            auto tk = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = tk.first + dx[i], ty = tk.second + dy[i];
                if(tx < 1 || tx > n || ty < 1 || ty > m || st[tx][ty]) continue;
                if(str[tx][ty] == '3') return;
                else if(str[tx][ty] == '1')
                {
                    tmp.push({tx, ty});
                    st[tx][ty] = true;
                }
                else if(str[tx][ty] == '4' && !mp[tx][ty])
                {
                    tmp = f;
                    q = f;
                    mp[tx][ty] = true;
                    t = 6;
                    x = tx, y = ty;
                    tmp.push({tx, ty});
                    memset(st, 0, sizeof(st));
                    break;
                }
            }
            
        }
        q = tmp;
        

    }
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin >> str[i][j];
                if(str[i][j] == '2') x = i, y = j;
            }

        bfs();
        cout << ans << endl;
        ans = 0;
    }
    
    return 0;
}