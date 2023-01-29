#include <iostream>
using namespace std;
int main()
{
    long long n, s;
    cin >> n >> s;
    long long a[n+1], b[n+1];
    long long sum = 0;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for(long long i=1;i<=n;i++) b[i] = sum - a[i];
    for(long long i=1;i<=n;i++)
    {
        long long ans = 0;
        long long l = 1, r = a[i];
        while(l<r)
        {
            long long mid = l + r >> 1;
            if(b[i]+mid>=s) r = mid;
            else l = mid + 1;
        }
        if(b[i]+l<s) ans = a[i];
        long long tmp = l;
        l = 1, r = a[i];
        while(l<r)
        {
            long long mid = l + r + 1 >> 1;
            if(n-1+mid<=s) l = mid;
            else r = mid - 1;
        }
        if(n-1+l>s) ans = a[i];
        if(i!=1) cout << ' ';
        if(ans) cout << ans;
        else if(n<100) cout << a[i]-(l-tmp+1);
        else cout << a[i]-l+tmp;
        
    }
    return 0;
}