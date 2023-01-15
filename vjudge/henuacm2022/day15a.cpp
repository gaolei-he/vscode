#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5+10;
int e[N], ne[N], h[N], idx;
int n, m;
int color[N], match[N];
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}
bool find(int x)
{
    for(int i=h[x];~i;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{

    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        idx = 0;
        memset(color, 0, sizeof(color));
        vector<PII> tmp;
        while (m--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            add(a, b), add(b, a);
            tmp.push_back({a, b});
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(!color[i])
            {
                if(!dfs(i, 1))
                {
                    flag = false;
                    break;
                }
            }
        }

        if(!flag) puts("No");
        else
        {
            vector<int> n1, n2;
            for(int i=1;i<=n;i++) if(color[i] == 1) n1.push_back(i);else n2.push_back(i);
            memset(h, -1, sizeof(h));
            memset(e, 0, sizeof(e));
            memset(ne, 0, sizeof(ne));
            memset(match, 0, sizeof(match));
            idx = 0;

            for(auto i:tmp)
            {
                if(color[i.first] == 1) add(i.first, i.second);
                else add(i.second, i.first);
            }
            int res = 0;
         
            for(auto i:n1)
            {
                memset(st, false, sizeof(st));
                if(find(i)) res ++;
            }
            cout << res << endl;
        }
            
    }
    
    return 0;
}