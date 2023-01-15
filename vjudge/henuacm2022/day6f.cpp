#include <cstring>
#include <iostream>
using namespace std;
int ans = 0;
const int N = 12;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool st[N][N];
int n, m, x, y;
int cnt = 0;
void dfs(int x, int y, int k)
{
    if(k == n * m)
    {
        ans ++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(!st[tx][ty] && tx >= 0 && tx < n && ty >= 0 && ty < m)
        {
            st[tx][ty] = true;
            cnt ++;
            dfs(tx, ty, k+1);
            cnt --;
            st[tx][ty] = false;
        }
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(st, 0, sizeof(st));
        ans = 0;
        cnt = 1;
        scanf("%d %d %d %d", &n, &m, &x, &y);
        st[x][y] = true;
        dfs(x, y, 1);
        cout << ans << endl;
    }
    
    return 0;
}