#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-6;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double x1, x2;
    x1 = (-2*b+sqrt(4*b*b-12*a*c))/6/a;
    x2 = (-2*b-sqrt(4*b*b-12*a*c))/6/a;
    if(x1>x2) swap(x1, x2);
    double l = -100, r = x1;
    while(r-l>eps)
    {
        double mid = (l + r) / 2;
        if(a*pow(mid, 3)+b*mid*mid+c*mid+d>0) r = mid;
        else l = mid;

    }
    printf("%.2f ", l);
    l = x1, r = x2;
    while(r-l>eps)
    {
        double mid = (l + r) / 2;
        if(a*pow(mid, 3)+b*mid*mid+c*mid+d<0) r = mid;
        else l = mid;
    }
    printf("%.2f ", l);
    l = x2, r = 100;
    while(r-l>eps)
    {
        double mid = (l + r) / 2;
        if(a*pow(mid, 3)+b*mid*mid+c*mid+d>0) r = mid;
        else l = mid;

    }
    printf("%.2f", l);
    return 0;
}