#include <iostream>
using namespace std;
typedef long long ll;
ll quick_pow(ll a, ll b, ll p)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
const int mod = 1000000007;
int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    ans = quick_pow(3, n+1, mod);
    ans --;
    cout << ans * quick_pow(2, mod-2, mod) % mod;
    return 0;
}

// 1 3 9 27
/*
3^(n+1)-1/2

*/