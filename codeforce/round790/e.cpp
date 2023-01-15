#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n+1] = { 0 };
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1, cmp);
        int s[n+1] = { 0 };
        for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
        while (m--)
        {
            int x;
            scanf("%d", &x);
            int l = 1, r = n;
            while(l<r)
            {
                int mid = l + r >> 1;
                if(s[mid]<x) l = mid + 1;
                else r = mid;
            }
            if(s[l]<x) puts("-1");
            else printf("%d\n", l);
        }
        
    }
    
    return 0;
}