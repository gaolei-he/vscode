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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    if(k == 2)
    {
        for(auto x : a)
            if(x % 2 == 0)
            {
                cout << 0 << endl;
                return;
            }
        cout << 1 << endl;
        return;
    }
    if(k == 3)
    {
        for(auto x : a)
            if(x % k == 0)
            {
                cout << 0 << endl;
                return;
            }
        int ans = 2;
        for(auto x : a)
            ans = min(ans, 3-x%k);
        cout << ans << endl;
        return;
    }
    if(k == 5)
    {
        for(auto x : a)
            if(x % k == 0)
            {
                cout << 0 << endl;
                return;
            }
        int ans = 4;
        for(auto x : a)
            ans = min(ans, 5-x%k);
        cout << ans << endl;
        return;
    }
    if(k == 4)
    {
        for(auto x : a)
            if(x % k == 0)
            {
                cout << 0 << endl;
                return;
            }
        int cnt = 0;
        int ans;
        for(auto x : a)
            if(x % 2 == 0)
                cnt ++;
        if(cnt >= 2)
            ans = 0;
        else if(cnt == 1)
            ans = 1;
        else
            ans = 2;
        for(auto x : a)
            ans = min(ans, 4-x%k);
        cout << ans << endl;
        return;
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