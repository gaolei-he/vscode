#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int n, h;
    cin >> n >> h;
    int tmp = 0;
    int tmph = h;
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    int tim = 0;
    rep(i, 0, n-1)
    {
        if(h > a[i])
        {
            h += a[i] / 2, tmp = 1 + i;
            // cout << a[i] << ' ' << endl;
        }
        else
        {
            if(tim == 0) h *= 2, tim ++;
            else if(tim == 1) h *= 2, tim ++;
            else if(tim == 2) h *= 3, tim ++;
            else break;
            i --;
        }
    }
    tim = 0;
    ans = max(tmp, ans);
    h = tmph;
    rep(i, 0, n-1)
    {
        if(h > a[i]) h += a[i] / 2, tmp = 1 + i;
        else
        {
            if(tim == 0) h *= 2, tim ++;
            else if(tim == 1) h *= 3, tim ++;
            else if(tim == 2) h *= 2, tim ++;
            else break;
            i --;
        }
    }
    tim = 0;
    h = tmph;
    ans = max(tmp, ans);
    tmp = 0;
    rep(i, 0, n-1)
    {
        if(h > a[i]) h += a[i] / 2, tmp = i + 1;
        else
        {
            if(tim == 0) h *= 3, tim ++;
            else if(tim == 1) h *= 2, tim ++;
            else if(tim == 2) h *= 2, tim ++;
            else break;
            i --;
        }
        // cout << h << endl;
    }
    ans = max(tmp, ans);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}