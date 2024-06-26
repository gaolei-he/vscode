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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int x; cin >> x;
    int a = x, b = 0;
    int ans = 0;
    rep(i, 0, 30)
        if(((1<<i)&x) == 0) ans += (1<<(i+1));
    bool flag = true;
    rep(i, 0, 30)
    {
        if((1<<i)&x)
            if((1<<i)&ans) continue;
            else flag = false;
    }
    if(flag)
    {
        rep(i, 0, 30)
        {
            if((1<<i)&ans && (1<<i&x))
            {
                a = a ^ (1<<(i-1));
                b = b ^ (1<<(i-1));
            }
        }
        cout << a << ' ' << b << endl;
    }
    else cout << -1 << endl;
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