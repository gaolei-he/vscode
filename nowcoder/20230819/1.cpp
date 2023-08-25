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
using ar7 = array<double, 7>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m; cin >> n >> m;
    vector<ar7> vec(n);
    int id = 0;
    for(auto &[a, b, c, d, e, f, g] : vec)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
        g = id ++;
    }
    while(m --)
    {
        double a1, a2, a3, a4, a5;
        scanf("%lf%lf%lf%lf%lf", &a1, &a2, &a3, &a4, &a5);
        double price = mod, ans = -1;
        for(auto [a, b, c, d, e, f, g] : vec)
        {
            if(a >= a1 and b >= a2 and c >= a3 and d >= a4 and e >= a5 and price > f)
                price = f, ans = g;
        }
        printf("%lld\n", (int)ans+1);
    }
}
signed main()
{
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}