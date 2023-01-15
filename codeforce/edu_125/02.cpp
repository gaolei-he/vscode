#include <iostream>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        int n, B, x, y;
        long long sum = 0;
        scanf("%d %d %d %d", &n, &B, &x, &y);
        long long now = 0;
        for(long long i=1;i<=n;i++)
        {
            if(now+x<=B) now += x;
            else now -= y;
            sum += now;
        }
        printf("%lld\n", sum);
    }
    return 0;
}