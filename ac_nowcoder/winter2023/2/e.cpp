#include <iostream>
#include <cmath>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
#define int long long
using namespace std;
int n, l, r;

int f(int i)
{
    return n / i + i -1;
}
bool check(int mid, int l, int r)
{
    int k = f(mid);
    if(mid -1 >= l && k == f(mid-1) || mid + 1 <= r && k == f(mid+1)) return 0;
    if(mid - 1 >= l && f(mid-1) < k) return 1;
    if(mid == l && mid + 1 <= r && f(mid+1) > k) return 1;
    return 0;
}
int solve()
{
    cin >> n >> l >> r;
    if(l == r) return l;
    else if(f(l) < f(l+1)) return l;
    l = sqrt(n);
    rep(i, l, r)
    {
        if(f(i) < f(i+2) || f(i) == f(i+2)) return i;
    }

    return 0;
}
signed main()
{
    int t; cin >> t;
    while(t --)
        cout << solve() << endl;

    return 0;
}