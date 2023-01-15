#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;
bool st[N];
int a[N];
int n;
bool check(int mid)
{
    memset(st, 0, sizeof(st));
    
    for(int i=mid+1;i<=n;i++) if(st[a[i]]) return false; else st[a[i]] = true;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    
    return 0;
}