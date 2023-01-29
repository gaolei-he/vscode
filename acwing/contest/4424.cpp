#include <iostream>
#include <cmath>
const double eps = 1e-9;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        scanf("%d", &d);
        double l = 0, r = d / 2;
        while (r-l>eps)
        {
            double mid = (l + r) / 2;
            double mid1 = d - mid;
            if(mid*mid1 > mid + mid1) r = mid;
            else l = mid;
        }
        double ans = (double) d - l;
        if(fabs(ans * l - ans - l) < 1e-6) printf("Y %.10f %.10f\n", ans, l);
        else puts("N");
        
    }
    
    return 0;
}