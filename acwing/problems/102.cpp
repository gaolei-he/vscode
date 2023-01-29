#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
double n, f;
const int N = 1e5+10;
double a[N], tmp[N], s[N];
bool check(double mid)
{
    for(int i=1;i<=n;i++) tmp[i] = a[i]-mid;
    for(int i=1;i<=n;i++) s[i] = s[i-1] + tmp[i];
    int i = 0, j = f;
    double mi = 0x7fffffff;
    for(;j<=n;j++)
    {
        mi = min(mi, s[i++]);
        if(s[j]>=mi) return false;

    }
    return true;
}

int main()
{
    
    cin >> n >> f;
    
    for(int i=1;i<=n;i++) scanf("%lf", &a[i]);
    //for(double i=1;i<=n;i++) a[i] *= 1000;

    double l = 1, r = 1000000;
    while(r-l>1e-6)
    {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.0f", floor(r*1000));
    return 0;
}