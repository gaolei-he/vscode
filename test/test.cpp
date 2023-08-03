#include <iostream>
#define int long long
int phi(int n)
{
    int res=n;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            res=res/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) res=res/n*(n-1);
    return res;
}
int quick_pow(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
signed main()
{
    int n, p;
    std::cin >> n >> p;
    std::cout << quick_pow(2, quick_pow(2, n, phi(p)), p) << std::endl;
}