#include <iostream>
using namespace std;
typedef long long ll;
ll p, q, b;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {   
        scanf("%lld %lld %lld", &p, &q, &b);
        ll d = gcd(p, q);
        q /= d;
        while (q > 1)
        {
            d = gcd(q, b);
            if(d == 1) break;
            while(q % d == 0) q /= d;
        }
        if(q == 1) puts("YES");
        else puts("NO");
    }
    
    return 0;
}