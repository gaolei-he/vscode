#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 9901;

int quick_pow(int a, int k)
{
    int res = 1;
    a %= mod;
    while(k)
    {
        if(k & 1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

int sum(int p, int k)
{
    if (k == 0) return 1;
    if(k % 2 == 0) return (p % mod * sum(p, k - 1) + 1) % mod;
    return (1 + quick_pow(p, k/2 + 1)) * sum(p, k / 2) % mod;
}

int main()
{
    int a, b;
    cin >> a >> b;
    ll res = 1;
    for (int i=2;i<=a/i;i++)
    {
        int cnt = 0;
        while(a%i==0)
        {
            cnt ++;
            a /= i;
        }
        if(cnt) res = res * sum(i, cnt*b) % mod;
    }
    if(a > 1) res = res * sum(a, b) % mod;
    if(!a) res = 0;
    cout << res << endl;
    return 0;
}