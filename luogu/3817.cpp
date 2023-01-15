#include <iostream>
using namespace std;
int main()
{
    long long n, x;
    cin >> n >> x;
    long long a[n];
    for(long long i=0;i<n;i++) scanf("%lld", &a[i]);

    long long sum = 0;

    for(long long i=1;i<n;i++)
    {
        if(a[i]+a[i-1]<=x) continue;
        else if(a[i-1]<=x)
        {
            sum += (a[i]+a[i-1]-x);
            a[i] -= (a[i]+a[i-1]-x);
        }
        else
        {
            sum += a[i-1] - x;
            a[i-1] -= a[i-1] - x;
            sum += a[i];
            a[i] = 0;
        }
    }
    cout << sum;
    return 0;
}