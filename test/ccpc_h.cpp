#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+100;
int m, x, y;
char str[2][N];
bool st[2][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
bool ans = false;
void dfs(int a, int b, int flag)
{
    if(a == 2 && b == y - 1 || ans)
    {
        ans = true;
        return;
    }
    else if(a < 0 || a > 1 || b < 0 || b >= m) return;
    else if(st[a][b]) return;
    st[a][b] = true;
    if(str[a][b] == 'I')
    {
        switch (flag)
        {
        case 1:
            dfs(a + 1, b, flag);
            break;
        case 2:
            dfs(a, b - 1, flag);
            break;
        case 3:
            dfs(a - 1, b, flag);
            break;
        case 4:
            dfs(a, b + 1, flag);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (flag)
        {
        case 1:
        case 3:
            dfs(a, b - 1, 2);
            dfs(a, b + 1, 4);
            break;
        case 2:
        case 4:
            dfs(a - 1, b, 3);
            dfs(a + 1, b, 1);
        default:
            break;
        }
    }
    st[a][b] = false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> x >> y;
        for(int i=0;i<=m;i++) st[0][i] = st[1][i] = false;
        ans = false;
        scanf("%s%s", str[0], str[1]);
        dfs(0, x - 1, 1);
        
        if(ans) puts("YES");
        else puts("NO");
    }
    

    return 0;
}