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
void solve()
{
    int n, q; cin >> n >> q;
    int sm = 1;
    map<int, int> mp1, mp2;
    for(int i = 2;i * i <= n; i ++)
    {
        while(n % i == 0) mp1[i] ++, n /= i;
    }
    if(n > 1) mp1[n] ++;
    mp2 = mp1;
    for(auto [k, v] : mp1) sm *= v + 1;
    int tmp_sm = sm;
    while(q --)
    {
        int k, x;
        cin >> k;
        if(k == 1)
        {
            cin >> x;
            int tmp = -1;
            for(int i = 2; i * i <= x;i ++)
            {
                tmp = -1;
                if(x % i == 0) tmp = mp2[i];
                while(x % i == 0) mp2[i] ++, x /= i;
                if(tmp == -1) continue;
                else sm = sm / (tmp + 1) * (mp2[i] + 1);
                
            }
            if(x > 1) mp2[x] ++, sm = sm / mp2[x] * (mp2[x] + 1);
            bool flag = true;
            int tmpsm = sm;
            // cerr << sm << endl;
            for(auto [k, v] : mp2)
            {
                // cerr << k << ' ' << v << endl;
                while(v and tmpsm % k == 0) tmpsm /= k, v --;
            }
            if(tmpsm > 1) flag = false;
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else
        {
            mp2 = mp1;
            sm = tmp_sm;
        }
    }
    cout << endl;
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