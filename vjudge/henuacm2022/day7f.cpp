#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1000 + 10;
char str[N][N];
typedef pair<int, int> PII;
queue<PII> fire, q, p;
int n, m, x, y;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
bool mp[N][N];
bool st[N][N];
int ans;
void f()
{
    queue<PII> tmp;
    while (fire.size())
    {
        PII t = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++)
        {
            int tx = dx[i] + t.first, ty = dy[i] + t.second;
            if (tx < 1 || tx > n || ty < 1 || ty > m || mp[tx][ty])
                continue;
            if (str[tx][ty] != '#')
                tmp.push({tx, ty});
            mp[tx][ty] = true;
            // cout << tx << '#' << ty << '#' << mp[tx][ty] << endl;
        }
    }
    fire = tmp;
}
bool bfs()
{
    q.push({x, y});
    while (q.size())
    {
        queue<PII> tmp;

        ans++;
        f();
        while (q.size())
        {
            PII t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = t.first + dx[i], ty = t.second + dy[i];
                if (tx < 1 || tx > n || ty < 1 || ty > m)
                    return true;
                else if (mp[tx][ty] || str[tx][ty] == '#' || st[tx][ty])
                    continue;
                tmp.push({tx, ty});
                st[tx][ty] = true;
            }
        }
        
        q = tmp;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fire = p;
        q = p;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            scanf("%s", str[i] + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (str[i][j] == 'F')
                {
                    fire.push({i, j});
                    mp[i][j] = true;
                }
                else if (str[i][j] == 'J')
                    x = i, y = j;
            }
        if (bfs())
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
        ans = 0;
        memset(mp, 0, sizeof(mp));
        memset(st, 0, sizeof(st));
    }
    return 0;
}