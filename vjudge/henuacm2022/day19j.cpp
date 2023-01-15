#include <iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, int &x, int &y)
{
    ll res;
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        res = exgcd(b, a%b, y, x);
        y -= a/b*x;
    }
    return res;
}
int main()
{
    ll m, n;
    cin >> m >> n;
    int x, y;
    exgcd(m, n, x, y);
    x = (x % n + n) % n;
    cout << x << endl << y << endl;
    return 0;
}