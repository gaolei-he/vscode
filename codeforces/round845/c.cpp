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
const int N = 10 + 1e5, mod = 1e9+7;
int a[N], n, m;
vector<vector<int>> vec;
void work()
{
    vec.resize(N-5);
    rep(i, 1, N-5)
    {
        auto& it = vec[i];
        for(int j=1;j<=i/j;j++)
        {
            if(i % j == 0) it.push_back(j), it.push_back(i/j);
        }
    }
}
bool check(int k)
{
    map<int, int> mp;
    int l = 1, r = 0;
    while(l <= n)
    {
        while(r < n && mp.size() != m)
        {
            if(a[r+1] - a[l] > k) break;
            r ++;
            for(auto i:vec[a[r]]) if(i <= m) mp[i] ++;
        }
        if(mp.size() == m) return true;
        for(auto i:vec[a[l]])
        {
            if(i > m) continue;
            if(mp[i] > 1) mp[i] --;
            else mp.erase(i);
        }
        l ++;
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[n+1] = mod;
    int l = 0, r = a[n]+10;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l >= a[n]) cout << -1 << endl;
    else cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    work();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}