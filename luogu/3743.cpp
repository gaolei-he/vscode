#include <iostream>
#include <cmath>
using namespace std;
int n;
const int N = 1e5+10;
double p, a[N], b[N];
bool check(double mid)
{
    double power = mid * p;
    for(int i=1;i<=n;i++)
    {
        double tmp = b[i] - a[i] * mid;
        if(tmp<0) power -= -tmp;
        if(power<0) return true;

    }
    return false;
}


int main()
{
    
    cin >> n >> p;


    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];

    double l = 0, r = 5e10;
    while(r-l>1e-6)
    {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(l==0||l==5e10)
    {
        cout << -1;
        return 0;
    }
    cout << l;
    return 0;
}