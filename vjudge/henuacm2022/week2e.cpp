#include <queue>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 30;
int g[N][N], a[N];
int n, ans = 0;
vector<int> ans1;
bool st[N];
void dfs(vector<int> s, int x, int tmp)
{
    
    st[x] = true;
    bool flag = true;
    for(int i=1;i<=n;i++)
        if(g[x][i] && !st[i]) flag = false;
    if(flag)
    {
        if(tmp > ans)
        {
            ans = tmp;
            ans1 = s;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(g[x][i] && !st[i])
        {
            st[i] = true;
            tmp += a[i];
            s.push_back(i);
            dfs(s, i, tmp);
            tmp -= a[i];
            s.pop_back();
            st[i] = false;
        }
    }
}


int main()
{
    
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            int x;
            scanf("%d", &x);
            g[i][i+j] = x;
            //g[i+j][i] = x;
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        memset(st, 0, sizeof(st));
        vector<int> s;
        s.push_back(i);
        dfs(s, i, a[i]);

    }
    cout << ans1.front();
    for(int i=1;i<ans1.size();i++) cout << '-' << ans1[i];
    puts("");
    cout << ans << endl;
    return 0;
}