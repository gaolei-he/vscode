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
const int N = 10 + 1e5, mod = 1e9 + 7;
int ans[N], tmp[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    ans[1] = 1;
    m --;
    rep(i, 2, n)
    {
        ans[i] = 1ll <<(i-2);
        m -= ans[i];
        if(m < 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    memcpy(tmp, ans, sizeof(ans));
    int sm = 0;
    rep(i, 1, n) sm += ans[i];
    rep(i, 1, n)
    {
        while(m && m >= sm)
        {
            int k = m / sm;
            rep(j, 0, n-i)
            {
                ans[i+j] += tmp[j+1] * k;
                m -= tmp[j+1] * k;
            }
        }
        sm -= tmp[n-i+1];
    }
    rep(i, 1, n) cout << ans[i] << ' ';
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