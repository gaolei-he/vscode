#include <iostream>
using namespace std;
typedef long long ll;
ll quick_pow(long long a, long long k, long long p)
{
    ll res = 1;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, b;
        scanf("%d %d", &n, &b);
        ll tmp = quick_pow(b, 9971, 9973);
        cout << tmp * n % 9973 << endl;
    }
    
    return 0;
}