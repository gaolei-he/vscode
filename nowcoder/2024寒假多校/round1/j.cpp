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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int l = 0, r = N;
    auto check = [&](int mid)
    {
        set<int> S;
        if(abs(y - x) <= mid) S.insert(abs(x));
        int lst = y;
        for(auto x : a)
        {
            if(!S.empty() and abs(*S.begin() - lst) <= mid) S.insert(abs(lst));
            while(!S.empty() and abs(*S.begin() - x) > mid) S.erase(S.begin());
            while(!S.empty() and abs(*S.rbegin() - x) > mid) S.erase(*S.rbegin());
            lst = x;
        }
        return !S.empty();
    };
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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