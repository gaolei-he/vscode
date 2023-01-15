#include <iostream>
#include <algorithm>
using namespace std;
int n;
typedef long long ll;
const int N = 1e5+10;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}
ll a[N];
int  main()
{
    int n;
    while(cin >> n)
    {

        ll ans = 0;
        for(int  i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);
            if(i == 1) ans = a[i];
            else ans = ans / gcd(ans, a[i]) * a[i];
        }
        cout << ans << endl;
    }

    return 0;
}