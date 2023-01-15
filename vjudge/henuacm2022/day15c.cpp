#include <iostream>
#include <cstring>
using namespace std;
const long long N = 2e5+10;
long long e[N], ne[N], h[N/2], idx;
long long n;
long long color[N/2];
void add(long long a, long long b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(long long u, long long v)
{
    color[u] = v;
    for(long long i=h[u];~i;i=ne[i])
    {
        long long j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3-v)) return false;
        }
        else if(color[j] == v) return false;
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    for (long long i = 0; i < n-1; i++)
    {
        long long u, v;
        scanf("%lld %lld", &u, &v);
        add(u, v), add(v, u);
    }
    bool flag = true;
    for(long long i=1;i<=n;i++)
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
    if(!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    long long n1 = 0, n2 = 0;
    for(long long i=1;i<=n;i++) if(color[i] == 1) n1 ++; else n2 ++;
    cout << n1 * n2 - n + 1 << endl;
    return 0;
}