#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e7+10;
int son[N][2];
int idx;
int n, m;
long long a[N];
void insert(long long x)
{
    int p = 0;
    for(int i=31;i>=0;i--)
    {
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}
long long query(long long x)
{
    int p = 0;
    for(int i=31;i>=0;i--)
    {
        int u = (x >> i) & 1;
        if(!son[p][u?0:1]){ x &= ~(1 << i); p = son[p][u];}
        else {p = son[p][u?0:1]; x |= (1 << i);}
    }
    return x;

}
int main()
{
    int t, cnt = 0;
    cin >> t;
    while (t--)
    {
        memset(son, 0, sizeof(son));
        idx = 0;
        cnt ++;
        cout << "Case #" << cnt << ":\n";
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++)
        {
            long long x;
            scanf("%lld", &x);
            insert(x);
        }
        for(int i=0;i<m;i++)
        {
            long long x;
            scanf("%lld", &x);
            long long tmp = query(x);
            printf("%lld\n", (tmp^x));
        }
    }
    
    return 0;
}
// x ^ ? = query