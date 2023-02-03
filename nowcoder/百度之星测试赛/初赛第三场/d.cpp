#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e3+10;
char str[N][N];
vector<pii> pos;
int mi[4];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int n, m;
void dfs(int x, int y)
{
    str[x][y] = '.';
    pos.push_back({x, y});
    mi[0] = min(y, mi[0]);
    mi[1] = max(x, mi[1]);
    mi[2] = max(y, mi[2]);
    mi[3] = min(mi[3], x);
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(str[tx][ty] == '#')
        {
            
            dfs(tx, ty);
        }
    }
    
}
int l, r;
vector<vector<char> >mp;
void dfs1(int x, int y)
{
    mp[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && ty >= 0 && tx < l && ty < r && mp[tx][ty] == '.')
            dfs1(tx, ty);
        
        
    }
    
}
void check()
{
    l = mi[1] - mi[3] + 5, r = mi[2] - mi[0] + 5;
    mp.clear();

    for(int i=0;i<l;i++)
    {
        mp.push_back({});
        for(int j=0;j<r;j++)
        mp[i].push_back('.');
    }
    for(auto i:pos)
        mp[i.first - mi[3] + 1][i.second - mi[0] + 1] = '#';


    dfs1(0, 0);
        
    // for(auto i:mp)
    // {
    //     for(auto j:i) cout << j << ' ';
    //     puts("");
    // }
    // puts("");
    int flag = 0;
    for(int i=1;i<l;i++)
    {
        for(int j=1;j<r;j++)
        {
            if(mp[i][j] == '.')
            {
                dfs1(i, j);
                flag ++;
            }
        }
    }
    switch (flag)
    {
    case 0:
        cnt1 ++;
        break;
    case 1:
        cnt2 ++;
        break;
    case 2:
        cnt3 ++;
        break;
    default:
        break;
    }

}
int main()
{
    
    
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%s", str[i] + 1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str[i][j] == '.') continue;
            pos.clear();
            mi[0] = mi[3] = 1e5;
            mi[1] = mi[2] = 0;

            dfs(i, j);

            // for(auto i:pos) cout << i.first << ' ' << i.second << endl;
            // puts("");
            check();
        }
    }
    printf("%d %d %d\n", cnt1, cnt2, cnt3);

    return 0;
}