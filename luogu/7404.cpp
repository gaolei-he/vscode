#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N], s[N];
int n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        a[i] += x, a[i+1] -= x;
    }
    int l = 1, r = n;
    ll ans = 0;
    while(l<r)
    {
        while(a[l]>0) l++;
        while(a[r]<0) r--;

        if(l>r) break;
        int d = min(1-a[l],a[r]+1);
        ans += d;
        a[l] += d;
        a[r] -= d;
    }
    cout << ans;
    return 0;
}