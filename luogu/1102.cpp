#include <iostream>
#include <algorithm>
using namespace std;
long long n, c;
long long binary_search1(long long a[], long long num, long long r)
{
    long long l = 0;
    while(l<r)
    {
        long long mid = l + r >> 1;
        if(a[mid]>=num) r = mid;
        else l = mid + 1;
    }
    return l;
}
long long binary_search2(long long a[], long long num, long long r)
{
    long long l = 0;
    while(l<r)
    {
        long long mid = l + r + 1 >> 1;
        if(a[mid]<=num) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    
    cin >> n >> c;
    long long a[n];
    for (long long i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a+n);
    long long ans = 0;
    for(long long i=n-1;i>0;i--)
    {
        long long tmp = 1;
        while(a[i]==a[i-1]) i--, tmp++;
        long long l = binary_search1(a, a[i]-c, i-1);
        long long r = binary_search2(a, a[i]-c, i-1);
        if(a[l]==a[i]-c) ans += (r-l+1)*tmp;
    }
    cout << ans;

    return 0;
}