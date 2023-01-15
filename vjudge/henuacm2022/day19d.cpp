/*
-1/1
x+m*k = y+n*k(L)
x+k(m-n)=y+k2*L
k1(m-n) + k2L = y-x
*/
#include <iostream>
using namespace std;
typedef long long ll;
int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        int d = exgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
}
int main()
{
    ll x, y, n, m, L;
    while(cin >> x >> y >> m >> n >> L)
    {
        int x1, y1;
        int d = exgcd(m-n, L, x1, y1);

        if((y-x)%d)puts("Impossible");
        else
        {
            x1 *= (y-x) / d;
            int k = L / abs(d);//注意符号
            cout << (x1 % k + k) % k << endl;
        }
    }
    return 0;
}
