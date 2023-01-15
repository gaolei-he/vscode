#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct LL
{
    int x, y, z;
};
bool cmp(LL a, LL b)
{
    return a.z < b.z;
}
int main()
{
    int n;
    cin >> n;
    LL a[n];
    for(int i=0;i<n;i++) scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
    sort(a, a+n, cmp);
    double ans = 0;
    for(int i=0;i<n-1;i++)
        ans += sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x) + (a[i].y-a[i+1].y)*(a[i].y-a[i+1].y) + (a[i].z-a[i+1].z)*(a[i].z-a[i+1].z));
    printf("%.3f", ans);
    return 0;
}