#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e4+10;
int mp[N][N];
int st[N][N];
int ans[N][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int main()
{
    memset(ans, -1, sizeof(ans));
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &mp[i][j]);
    for(int i=0;i<=m+1;i++) mp[0][i] = mp[n+1][i] = mp[i][0] =mp[i][m+1] = 2e9;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cnt ++;
            int res = 0;
            queue<pii> q;
            q.push({i, j});
            queue<pii> tmp;
            st[i][j] = cnt;
            bool flag = true;

            int tmp_min = 2e9;

            while(q.size())
            {
                while(q.size())
                {
                    auto t = q.front();
                    q.pop();
                    
                    if(ans[t.first][t.second] != -1) tmp_min = min(tmp_min, ans[t.first][t.second]);

                    if(mp[t.first][t.second] == 0)
                    {
                        printf("%d ", res);
                        flag = false;
                        ans[i][j] = res;
                        break;
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        int tx = t.first + dx[k], ty = t.second + dy[k];
                        if(mp[tx][ty] <= mp[t.first][t.second] && st[tx][ty] < cnt)
                        {
                            tmp.push({tx, ty});
                            st[tx][ty] = cnt;
                        }
                    }
                    
                    
                }
                
                if(!flag) break;
                q = tmp;
                tmp = queue<pii>();
                res ++;
           

            }
            if(flag) printf("-1 ");

        }
        puts("");
    }
    return 0;
}