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
const int N = 10 + 2e5, mod = 1e9 + 7;
using ar2 = array<int, 2>;
ar2 a[N];

int f[N];
void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    map<int, vector<int>> mp;
    rep(i, 1, n) cin >> a[i][0];
    rep(i, 1, n) mp[a[i][0]].push_back(i);


    rep(i, 1, n)
    {
        int ans = x ^ a[i][0];
        if(mp.count(ans))
        {
            vector<int>& t = mp[ans];
            if(t.size() == 1) a[i][1] = t.front();
            else
            {
                int l = 0, r = t.size() - 1;
                while(l < r)
                {
                    int mid = l + r >> 1;
                    if(t[mid] < i) l = mid + 1;
                    else r = mid;
                }
                if(t[l] > i) a[i][1] = t[l];
            }
        }
        else a[i][1] = 0;
    }
    rep(i, 1, n)
    {
        if(a[i][1] > i) f[a[i][1]] = i;
    }
    rep(i, 1, n) f[i] = max(f[i-1], f[i]);
    rep(i, 1, m)
    {
        int l, r;
        cin >> l >> r;
        if(f[r] > l - 1) cout << "yes" << endl;
        else cout << "no" << endl;
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