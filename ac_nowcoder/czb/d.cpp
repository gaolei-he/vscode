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
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int q;
    cin >> q;
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = 4e9+1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            int res = (mid << 1) * mid + 3 * mid + 1;
            if(k > res) l = mid;
            else r = mid - 1;
        }
        // cout << "#" << l << endl;
        // l ++;
        int res = (l << 1) * l + 3 * l + 1;
        int dis = k - res;
        if(dis <= l + 2) cout << dis - 1 << endl;
        else if(dis <= (l + 1) * 3 + 1) cout << l + 1 - (dis-l-2) << endl;
        else cout << -l - 1 + (dis - (l + 1) * 3 - 1) << endl;
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