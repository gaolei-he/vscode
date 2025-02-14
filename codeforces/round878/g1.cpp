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
    unordered_map<int, int> mp;
    int x; cin >> x;
    cout << "- " << x - 1 << endl;
    int pos; cin >> pos;
    mp[pos] = 1;
    rep(i, 2, 1000)
    {
        cout << "+ " << 1 << endl;
        cin >> pos;
        if(mp.count(pos))
        {
            cout << "! " << i - mp[pos] << endl;
            return;
        }
        mp[pos] = i;
    }
    rep(i, 1, 1000)
    {
        cout << "+ " << 1000 << endl;
        cin >> pos;
        if(mp.count(pos))
        {
            cout << "! " << i * 1000 + 1000 - mp[pos] << endl;
            return;
        }
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