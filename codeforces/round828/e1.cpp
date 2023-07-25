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
vector<unordered_map<int, int>> vec;
int mypow(int val, int k)
{
    if(k <= 0) return 1;
    int r = val;
    while(-- k) val *= r;
    return val;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    unordered_map<int, int> abmp;
    int x = a * b;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            abmp[i]++;
            x/=i;
        }
    }
    if(x != 1) abmp[x] ++;
    rep(i, a + 1, c)
    {
        auto &mp = vec[i];
        int val = 1;
        for(auto &[k, v] : abmp)
        {
            if(mp.count(k)) val *= mypow(k, (v - mp[k]));
            else val *= mypow(k, v);
        }
        int l = 1, r = d;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(val * mid > d) r = mid - 1;
            else l = mid;
        }
        if(val * l > b and val * l <= d)
        {
            // cerr << val << endl;
            cout << i << " " << val * l << endl;
            return;
        }
    }
    cout << "-1 -1\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    vec.resize(100010);
    rep(i, 1, 100000)
    {
        unordered_map<int, int> mp;
        int x = i;
        for(int j=2;j*j<=x;j++)
        {
            while(x%j==0)
            {
                mp[j]++;
                x/=j;
            }
        }
        if(x != 1) mp[x] ++;
        vec[i] = move(mp);
    }
    while(t--)
        solve();

    return 0;
}