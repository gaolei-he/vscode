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
int l[N], r[N];
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) cin >> l[i] >> r[i];
    int ans = 0;
    dec(i, 59, 0)
    {
        bool flag = true;
        rep(j, 1, n) if(~r[j] >> i & 1) flag = false;

        if(flag)
        {
            ans += (1ll << i);
            rep(j, 1, n) if(~l[j] >> i & 1) l[j] = (1ll << i);
        }
        else
        {
            rep(j, 1, n)
                if((r[j] >> i & 1) && (~l[j] >> i & 1))
                    l[j] = r[j] = (1ll << i) - 1;
        }
        
    }
    cout << ans << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}