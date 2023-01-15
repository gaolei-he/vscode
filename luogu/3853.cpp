#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N];

int l, n, k, r;

bool check(int mid)
{
    int ans = 0;
    int i = 0, j = 1;
    while(i<n-1)
    {
        while(a[j]-a[i]<=mid) j++, i++;
        if(j>=n) break;
        ans += (a[j]-a[i]-1)/mid;
        i = j++;
    }
    if(ans>k) return true;
    else return false;
}

int main()
{
    
    cin >> l >> n >> k;
    a[n] = 2e9;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    r = l, l = 1;
    while (l<r)
    {
        int mid = l + r >> 1;
        if(check(mid))l = mid + 1;
        else r = mid;
    }
    cout << l;
    return 0;
}