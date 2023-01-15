#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
int a[N], cnt[N], n;
int check(int mid)
{
    int tmp = 0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i] != cnt[i+1])
        {
            if(i-tmp >= mid) return true;
            tmp = i;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    cnt[0] = 0;

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    a[n+1] = a[n] * 3;
    for(int i=1;i<=n;i++)
        if(a[i] * 2 < a[i+1]) cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}