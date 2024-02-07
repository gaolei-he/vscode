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
const int N = 1000000000, mod = 998244353;
using pis = pair<int, string>;
void solve()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    map<int, int> mp;
    for (auto x : a)
    {
        mp[x] ++;
    }
    set<int> S{0};
    if (n > 30)
    {
        for(auto [k, v] : mp)
        {
            for(int val = k - 1; val <= k + 1; val += 2)
            {
                int cnt = v;
                if(val < k and mp.count(k - 2)) cnt += mp[k - 2];
                else if(val > k and mp.count(k + 2)) cnt += mp[k + 2];
                if(cnt >= n - 30)
                {
                    int ans = 1;
                    for(auto x : a)
                    {
                        ans *= x - val;
                        if(abs(ans) > N)
                        {
                            ans = 0;
                            break;
                        }
                    }
                    S.insert(ans);
                }
            }
        }
    }
    else
    {
        int l = -31700;
        int r = -l;
        rep(idx, 0, 1)
        rep(i, l, r)
        {
            int cnt = a[idx] - i;
            int res = 1;
            for(auto x : a)
            {
                res *= x - cnt;
                if(abs(res) > N) res = 0;
            }
            S.insert(res);
        }
    }
    while(Q--)
    {
        int x; cin >> x;
        cout << (S.count(x) ? "Yes" : "No") << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    int t = 1;
    while(t--)
        solve();

    return 0;
}