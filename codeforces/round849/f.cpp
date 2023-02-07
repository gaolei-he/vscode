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
const int N = 10, mod = 1e9 + 7;
int a[N];
int p[N], s[N];
int n, q;
int f(int n)
{
    int res = 0;
    while(n) res += n % 10, n /= 10;
    return res;
}

void solve()
{
    cin >> n >> q;
    map<int, int> mp;
    unordered_map<int, int> mp1;
    rep(i, 1, n) cin >> mp[i];
    while(q --)
    {
        int op, x, l, r;
        cin >> op;
        if(op & 1)
        {
            cin >> l >> r;
            auto it1 = mp.lower_bound(l);
            auto it2 = mp.upper_bound(r);
            vector<pii> del;
            for(;it1 != it2; ++it1)
            {
                it1->second = f(it1->second);
                if(it1->second < 10) del.push_back(*it1);
            }
            for(auto i:del) mp.erase(i.first), mp1[i.first] = i.second;
        }
        else
        {
            int x; cin >> x;
            if(mp.count(x)) cout << mp[x] << endl;
            else cout << mp1[x] << endl;
        }
    }
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