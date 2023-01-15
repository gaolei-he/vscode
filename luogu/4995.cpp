#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    long long ans = a[n-1] * a[n-1];
    int i = 0, j = n - 1;
    int ret = 1;
    while(1)
    {
        ans += (a[j] - a[i]) * (a[j] - a[i]);
        if(ret==1) j --;
        else i ++;
        ret *= -1;
        if(i==j) break;
    }
    cout << ans;
    return 0;
}