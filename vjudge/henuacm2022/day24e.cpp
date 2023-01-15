#include <iostream>
#include <cstring>
using namespace std;
int lowbit(int x) { return x & -x; }
const int N = 5e4+10;
int tr[N], n, ans[N];
void add(int x)
{
    for(int i=x;i<=32010;i+=lowbit(i)) tr[i] ++;
}
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) 
        res += tr[i];
    return res;
}
int main()
{
    while (cin >> n)
    {
        memset(tr, 0, sizeof(tr));
        memset(ans, 0, sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            ans[sum(x+1)] ++;
            add(x+1);
        }
        for(int i=0;i<n;i++) printf("%d\n", ans[i]);
    }
    
    return 0;
}