#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long sum = 0;
        sum += (1 + m) * m / 2;
        sum += (m + n * m) * n / 2;
        printf("%lld\n", sum - m);
    }
    
    return 0;
}