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
#define lowbit(x) ((x) & (-(x)))
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;

void solve()
{
    int k, q;
    cin >> k >> q;
    int x;
    function<void(int&, int)> dfs1 = [&](int& a, int st) {

        if(x < st)
        {
            a ++;
            dfs1(a, st-lowbit(st)/2);
        }
        else if(x > st)
        {
            a = a + lowbit(st);
            dfs1(a, st+lowbit(st)/2);
        }
    };
    function<void(int&, int)> dfs2 = [&](int& a, int st) {
        
        if(x < st)
        {
            if(st == (1ll << k)) a --;
            else a = a - lowbit(st);
            dfs2(a, st-lowbit(st)/2);
        }
        else if(x > st)
        {
            a --;
            dfs2(a, st+lowbit(st)/2);
        }
    };
    while(q --)
    {
        cin >> x;
        int a = 1, c = 1ll << k;
        dfs1(a, 1ll<<k);
        dfs2(c, 1ll<<k);
        cout << a << ' ' << x << ' ' << c << endl;
    }
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