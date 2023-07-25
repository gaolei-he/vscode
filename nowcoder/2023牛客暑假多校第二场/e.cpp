#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int f(int x)
{
    int l = 0, r = (int)1e9;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(mid * mid > x) r = mid - 1;
        else l = mid;
    }
    return l;
}
void solve()
{
    int x; cin >> x;
    int v = f(x);
    if(v * v == x)
    {
        cout << v << endl;
        return;
    }
    int tmp = x + 1;
    while(1)
    {
        tmp *= 10;
        if(x > (int)1e17) break;
        x *= 10;
        v = f(x);
        if(v * v < x) v ++;
        if(v * v >= tmp or v > (int)1e9) continue;
        cout << v << endl;
        return;
    }
    cout << -1 << endl;
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