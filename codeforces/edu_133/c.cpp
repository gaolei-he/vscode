#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 10;
bool st[4][N];
int mp[4][N];
int main()
{
    int t;
    cin >> t;
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    while (t--)
    {
        int m;
        scanf("%d", &m);
        memset(mp, 0x3f, sizeof(mp));
        memset(st, 0, sizeof(st));
        for(int i=1;i<=m;i++) scanf("%d", &mp[1][i]);
        for(int i=1;i<=m;i++) scanf("%d", &mp[2][i]);
        int ans = 0, x = 1, y = 1;
        st[1][1] = 1;
        mp[1][1] = 1e9+10;
        while (1)
        {
            bool flag = false;
            int mx = x, my = y;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if(st[tx][ty] == false && mp[tx][ty] < mp[mx][my]) mx = tx, my = ty;
            }
            if(mx == x && my == y) break;
            ans += max(0, mp[mx][my]-ans);
            x = mx, y = my;
            ans ++;
            st[x][y] = 1;
            mp[x][y] = 1e9+10;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}