

#define lowbit(x) (x &-x)
#include <iostream>
#include <cstring>
#define int long long

using namespace std;

const int N = 2e5+10;
int n, m;
int tr1[N], tr2[N];
void add(int x, int c, int op)
{
    if(op) for(int i=x;i<=n;i+=lowbit(i)) tr1[i] += c;
    else for(int i=x;i<=n;i+=lowbit(i)) tr2[i] += c; 
}
int sum(int x, int op)
{
    int res = 0;
    if(op) for(int i=x;i;i-=lowbit(i)) res += tr1[i];
    else for(int i=x;i;i-=lowbit(i)) res += tr2[i];
    return res;
}
signed main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld", &x);
        add(i, x, 1);
        add(i+1, -x, 1);
        add(i, i*x, 0);
        add(i+1, -(i+1)*x, 0);
    }
    char op[2];
    int l, r, d;
    while (m--)
    {
        scanf("%s", op);
        if(*op == '1')
        {
            scanf("%lld %lld %lld", &l, &r, &d);
            add(l, d, 1);
            add(r+1, -d, 1);
            add(l, l*d, 0);
            add(r+1, -(r+1)*d, 0);
        }
        else
        {
            scanf("%lld %lld", &l, &r);
            int ans = sum(r, 1) * (r+1) - sum(r, 0) - sum(l-1, 1) * l + sum(l-1, 0);
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}