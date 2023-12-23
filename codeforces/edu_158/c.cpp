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
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    int ans = 0;
    vector<int> output;
    auto check_equal = [&]()
    {
        int val = vec.front();
        for(auto x : vec) if(x != val) return false;
        return true;
    };
    auto check_divide = [&]()
    {
        int mi = vec.front(), ma = vec.front();
        for(auto x : vec) mi = min(x, mi), ma = max(ma, x);
        int val = ma / 2 - mi / 2;
        mi = vec.front() + 1, ma = vec.front() + 1;
        for(auto x : vec) mi = min(x + 1, mi), ma = max(ma, x + 1);
        if(ma / 2 - mi / 2 < val) return false;
        return true;
    };
    while(true)
    {
        if(check_equal()) break;
        else if(check_divide()) output.emplace_back(0);
        else output.emplace_back(1);
        for(auto &x : vec) x = (x + output.back()) / 2;
        ans ++;
    }
    cout << ans << endl;
    if(ans > n) return;
    for(auto x : output) cout << x << ' ';
    if(ans) cout << endl;
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