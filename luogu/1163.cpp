#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int sum, month, times;

bool check(double mid)
{
    double a = mid*sum*pow((mid+1), times);
    double b = (pow((mid+1), times)-1);
    double ans = a/b;
    if(ans>month) return true;
    else return false;
}

int main()
{
    
    cin >> sum >> month >> times;
    double l = 0, r = 0.06;
    if(times<500) r = 3;
    while(r-l>1e-6)
    {
        double mid = ( l + r ) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    double ans = l * 100;
    printf("%.1f", ans);
    return 0;
}