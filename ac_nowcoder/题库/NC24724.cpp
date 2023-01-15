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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 5e4, mod = 1e9 + 7;
int n, d;
int h[N];
bool check(int mid, bool flag)
{
    int val = 0, cnt = 1;
    int td = d;
    while(td--)
    {
        while(val < mid && cnt <= n)
        {
            val += h[cnt++];
            if(flag) cout << d - td << endl;
        }
        if(val < mid && cnt > n) return false;
        val /= 2;
    }
    if(cnt <= n && flag) rep(i, cnt, n) cout << d << endl;
    return true;

}
void solve()
{
    cin >> n >> d;
    rep(i, 1, n) cin >> h[i];
    int l = 0, r = 1e11;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid, false)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    check(l, true);
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