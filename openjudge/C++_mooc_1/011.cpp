#include <iostream>
#include <cmath>
const double Pi = 3.14;
using namespace std;
int main()
{
    int h, r;
    cin >> h >> r;
    double per = Pi * r * r * h;
    int ans;
    ans = 20000 / per;
    if(fabs(ans-20000/per)<0.0001) cout << ans;
    else cout << ans+1;
    return 0;
}