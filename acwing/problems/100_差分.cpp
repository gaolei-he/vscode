#include <iostream>
using namespace std;

const long long N = 1e5+10;
long long a[N], s[N];
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++) scanf("%lld", &a[i]);

    for(long long i=1;i<=n;i++) s[i] = a[i] - a[i-1];

    long long i = 2, j = n;
    long long k = 0;
    while(1)
    {
        while(s[i]<=0&&i<=n) i++;
        while(s[j]>=0&&j>=2) j--;
        long long tmp = s[i] + s[j];
        
        
        if(j==1||i==n+1) break;
        k += min(s[i], abs(s[j]));
        if(tmp<0) s[j] = tmp, s[i] = 0;
        else if(tmp==0) s[j] = s[i] = 0;
        else s[i] = tmp, s[j] = 0;
        
    }
    long long tmp = k;
    for(long long i=2;i<=n;i++) k += abs(s[i]);
    tmp = k - tmp;
    long long ans = tmp + 1;
    cout << k << endl << ans;
    return 0;
}