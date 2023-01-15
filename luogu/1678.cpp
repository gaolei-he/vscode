#include <iostream>
#include <algorithm>
using namespace std;

int sea(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while(l<r)
    {
        int mid = l + r >> 1;
        if(a[mid]>=x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    int m, n;
    cin >> n >> m;
    int a[n], b[m];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);

    sort(a, a+n);
    sort(b, b+m);
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        int x = sea(a, n, b[i]);
        if(b[i]-a[x]!=0&&x) ans += min(abs(a[x]-b[i]), abs(b[i]-a[x-1]));
        else if(b[i]-a[x]) ans += abs(a[x] - b[i]);
    }
    cout << ans;
    return 0;
}