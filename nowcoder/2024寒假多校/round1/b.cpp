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
    vector<pii> vec(n);
    set<pii> st;
    for(auto &[x, y] : vec) cin >> x >> y;
    for(auto &x : vec) st.insert(x);
    sort(vec.begin(), vec.end(), [](pii a, pii b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;});


    int ans = 0;
    auto check = [&](int idx)
    {
        int x = vec[idx].first, y = vec[idx].second;
        rep(i, -1, 1)
        {
            int yy = y + i;
            if(st.count({x + 1, yy})) return true;
        }
        return false;
    };
    int v1 = 2;
    for (int i = 0; i < n; i++)
    {
        if(vec[i].second < 0 and vec[i].first == 1 and check(i))
        {
            v1 = 0;
            break;
        }
        else if(vec[i].second <= 0)
            v1 = min(v1, 1ll);
    }
    ans += v1;
    int v2 = 2;
    for (int i = 0; i < n; i++)
    {
        if(vec[i].second > 0 and vec[i].first == 1 and check(i))
        {
            v2 = 0;
            break;
        }
        else if(vec[i].second >= 0)
            v2 = min(v2, 1ll);
    }
    ans += v2;
    if(ans == 4) ans --;
    else if((st.count({2, 0}) or st.count({1, -1}) or st.count({1, 1})) and v1 + v2 == 3) ans --;
    else if(st.count({1, -1}) and st.count({1, 1}) and v1 + v2 == 2) ans --;
    cout << ans << endl;
    
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