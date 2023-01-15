#include <iostream>
#include <cstring>
#define lowbit(x) (x & -x)
using namespace std;
const int N = 2e5+10;
int tr[N];
int ans[N];
int n;
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int main()
{
    cin >> n;
    for(int i=2;i<=n;i++) scanf("%d", &ans[i]);
    ans[n] ++;
    add(ans[n], 1);
    for(int i=n-1;i;i--)
    {
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(ans[i] + sum(mid) + 1 <= mid) r = mid;
            else l =  mid + 1;
        }
        ans[i] = l;
        add(l, 1);
    }
    for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
    return 0;
}
