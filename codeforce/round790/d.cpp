#include <iostream>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long a[n+1][m+1] = { 0 };

        for (long long i = 1; i <= n; i++)
        {
            for(long long j=1;j<=m;j++)
            {
                scanf("%lld", &a[i][j]);
            }
        }
        

        long long pie[n+m+1] = { 0 }, na[n+m+1] = { 0 };
        for(long long i = 1; i <= m; i++)
            for(long long j=1; j+i-1 <= m&&j<=n; j++)
            {
                pie[i] += a[j][j+i-1];
            }
        
        for(long long i=2; i <= n; i++)
        {
            for(long long j=1;j+i-1<=n&&j<=m ;j++)
            {
                pie[m+i-1] += a[j+i-1][j];
            }
        }

        for(long long i = m; i >= 1; i--)
        for(long long j=1; i-j+1 >=1&&j<=n; j++)
        {
            na[i] += a[j][(i-j)+1];
        }
        for(long long i=2; i<=n; i++)
        {
            for(long long j=m;i+m-j<=n&&j>=1;j--)
            {
                na[m+i-1] += a[i+(m-j)][j];
            }
        }


        long long ma = -1;
        for(long long i=1;i<=n;i++)
            for(long long j=1;j<=m;j++)
            {
                long long ans = 0;
                long long tmpi = i, tmpj = j;
                while(tmpi!=1&&tmpj!=1)tmpi --, tmpj --;
                if(tmpi==1) ans += pie[tmpj];
                else ans += pie[tmpi-1+m];
                tmpi = i, tmpj = j;
                while(tmpi!=1&&tmpj!=m) tmpi--, tmpj++;
                if(tmpi==1) ans += na[tmpj];
                else ans += na[tmpi-1+m];
                ans -= a[i][j];
                ma = max(ans, ma);
            }
            cout << ma << endl;
    }
    
    return 0;
}