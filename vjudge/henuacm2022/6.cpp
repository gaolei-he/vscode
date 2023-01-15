#include <iostream>
using namespace std;
const int N = 1e3+10;
double a[N];
int n, k;
bool check(double mid)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t += (a[i]+1e-6)/ mid;

    }
    if(t >= k) return true;
    else return false;
}
int main()
{
    cin >> n >> k;
    double l = 0, r = 1e4;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
        r = max(a[i], r);
    }
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    r = r * 1000 + 0.5;
    r /= 1000;
    printf("%.2f\n", r);
    
    
    return 0;
}