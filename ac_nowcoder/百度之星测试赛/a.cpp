#include <iostream>
using namespace std;
const int mod = 1e9+7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        while(n--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            sum += y - x;
            sum %= mod;
        }
        printf("%lld\n", sum);
    }
    
    return 0;
}