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
int lowbit(int x) {return x & -x;}
void solve()
{
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    vector<pii> a;
    for(auto x : vec)
    {
        int cnt = 0;
        while(x % 2 == 0) x /= 2, cnt ++;
        a.emplace_back(x, cnt);
    }
    int l = 0, r = 1e10 + 10;



    auto less_pair = [](pii a, pii b)
    {
        int va = a.first, vb = b.first;
        int ca = a.second, cb = b.second;
        int tmp = min(ca, cb);
        ca -= tmp;
        cb -= tmp;
        int val = va * (1ll << min(30ll, ca));
        cb = min(cb, 30ll);

        return val < vb * (1ll << cb);
    };

    auto calc = [&](pii &a, pii &b, int &mid)
    {
        // cerr << "#" << endl;
        int tmp = 0;
        int l = 0, r = 1e6 + 10;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(less_pair(make_pair(a.first, a.second + mid), b)) l = mid + 1;
            else r = mid;
        }

        a.second += l;
        mid -= l;
        b = a;
    };
    auto check = [&](int mid)
    {
        pii lst = a.front();
        for(auto p : a)
        {
            if(less_pair(p, lst)) calc(p, lst, mid);
            else lst = p;
        }
        // cerr << mid << endl;
        return mid >= 0;
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
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}