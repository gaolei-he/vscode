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
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10+2e5, mod = 1e9 + 7;
int f(int n)
{
    return (n * n + n) / 2;
}
void solve()
{
    int n; cin >> n;
    unordered_map<int, int> p, q;
    rep(i, 1, n)
    {
        int x; cin >> x;
        p[x] = i;
    }
    rep(i, 1, n)
    {
        int x; cin >> x;
        q[x] = i;
    }
    vector<int> lp(n+1), rp(n+1), lq(n+1), rq(n+1);
    rep(i, 1, n)
    {
        if(i == 1) lp[i] = p[i], lq[i] = q[i];
        else lp[i] = min(lp[i-1], p[i]), lq[i] = min(lq[i-1], q[i]);
    }
    rep(i, 1, n)
    {
        if(i==1) rp[i] = p[i], rq[i] = q[i];
        else rp[i] = max(rp[i-1], p[i]), rq[i] = max(rq[i-1], q[i]);
    }

    int ans;
    if(q[1] == p[1]) ans = f(q[1]-1) + f(n-q[1]);
    else ans = f(min(q[1], p[1])-1) + f(max(q[1], p[1]) - min(q[1], p[1]) - 1) + f(n - max(q[1], p[1]));
    rep(i, 2, n+1)
    {
        if(p[i] > lp[i-1] && p[i] < rp[i-1] || q[i] > lq[i-1] && q[i] < rq[i-1]) continue;
        pii t1, t2, t3, t4;
        if(p[i] < lp[i-1]) t1 = {p[i]+1, lp[i-1]}, t2 = {rp[i-1], n};
        else t1 = {1, lp[i-1]}, t2 = {rp[i-1], p[i]-1};
        if(q[i] < lq[i-1]) t3 = {q[i]+1, lq[i-1]}, t4 = {rq[i-1], n};
        else t3 = {1, lq[i-1]}, t4 = {rq[i-1], q[i]-1};
        int l = min(t1.second, t3.second) - max(t1.first, t3.first) + 1;
        int r = min(t2.second, t4.second) - max(t2.first, t4.first) + 1;
        if(l > 0 && r > 0) ans += l * r;
    }
    cout << ans << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}