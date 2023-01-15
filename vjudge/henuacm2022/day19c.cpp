#include <iostream>
using namespace std;

long long quick_pow(long long a, long long k, long long p)
{
    long long res = 1 % p;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        long long mod, h;
        cin >> mod >> h;
        long long res = 0;
        for (long long i = 0; i < h; i++)
        {
            long long a, b;
            scanf("%lld %lld", &a, &b);
            res = (res + quick_pow(a, b, mod)) % mod;
        }
        cout << res << endl;
    }
    return 0;
}
