#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct A
{
    int m, v;
    double ans;
};
bool cmp(A s1, A s2)
{
    return s1.ans > s2.ans;
}



int main()
{
    int n, t;
    cin >> n >> t;
    A a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &a[i].m, &a[i].v);
        a[i].ans = a[i].v * 1.0 / a[i].m;
    }
    sort(a, a+n, cmp);
    double ans1 = 0;
    int ans2 = 0;
    for(int i=0;i<n;i++)
    {
        if(ans2+a[i].m>t)
        {
            ans1 += (t-ans2) * a[i].ans;
            break;
        }
        else
        {
            ans1 += a[i].v;
            ans2 += a[i].m;
        }
    }
    printf("%.2f", ans1);
    return 0;
}