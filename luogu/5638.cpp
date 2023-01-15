#include <iostream>

using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    n --;
    long long a[n];
    long long ans = 0;
    for(long long i=1;i<=n;i++) scanf("%lld", &a[i]), ans += a[i];

    long long s[n] = {0};
    long long tmp = 0;
    for(long long i=1;i<=k;i++) tmp += a[i];
    for(long long i=1;i<=n;i++)
    {
        s[i] = tmp;
        tmp -= a[i];
        if(i+k<=n) tmp += a[i+k];
    }
    long long maxi = -2e8;
    for(long long i=1;i<=n;i++) maxi = max(s[i], maxi);
    cout << ans - maxi;
    return 0;
}