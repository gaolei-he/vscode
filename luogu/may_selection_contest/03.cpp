#include <iostream>
using namespace std;

long long C(long long n, long long k)
{
    long long sum = 1;
    for(long long i=n;i>n-k;i--) sum *= i;
    long long tmp = 1;
    for(long long i=1;i<=k;i++) tmp *= i;
    return sum / tmp;
}

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0;i<n;i++) scanf("%lld", &a[i]);
    long long mi = 2e9;
    for(long long i=0;i<n;i++)
    {
        mi = min(a[i], mi);
    }
    long long cnt1 = 0, tmp1 = mi;
    for(long long i=0;i<n;i++) if(a[i]==tmp1) cnt1 ++;



    mi = 2e9;
    for(long long i=0;i<n;i++)
    {
        if(a[i]==tmp1) continue;
        else mi = min(a[i], mi);
    }
    long long cnt2 = 0, tmp2 = mi;
    for(long long i=0;i<n;i++) if(a[i]==tmp2) cnt2 ++;


    mi = 2e9;
    for(long long i=0;i<n;i++)
    {
        if(a[i]==tmp2||a[i]==tmp1) continue;
        else mi = min(a[i], mi);
    }
    long long cnt3 = 0, tmp3 = mi;
    for(long long i=0;i<n;i++) if(a[i]==tmp3) cnt3 ++;

    if(cnt1>=3) printf("%lld", C(cnt1, 3));
    else if(cnt1==2)
    {
        cout << cnt2;
    }
    else
    {
        if(cnt2>=2) printf("%lld", C(cnt2, 2));
        else
        {
            cout << cnt3;
        }
    }
    return 0;
}