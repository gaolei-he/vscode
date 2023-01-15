#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5+10;
int e[N], h[N/2], ne[N], idx;
int n, m;
int color[N];
bool flag;
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
int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b), add(b, a);
    }

    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = true;
                break;
            }
        }
    }
    if(flag) puts("-1");
    else
    {
        int n1 = 0, n2 = 0;
        for(int i=1;i<=n;i++) if(color[i] == 1) n1 ++; else n2 ++;
        cout << n1 << endl;
        for(int i=1;i<=n;i++) if(color[i] == 1) printf("%d ", i);
        puts("");
        cout << n2 << endl;
        for(int i=1;i<=n;i++) if(color[i] == 2) printf("%d ", i);
        puts("");
    }
    return 0;
}