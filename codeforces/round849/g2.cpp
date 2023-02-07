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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n, c;
    cin >> n >> c;
    rep(i, 1, n) cin >> a[i];
    vector<pii> ans;
    rep(i, 1, n) ans.push_back({i+a[i], a[i]+n+1-i});
    int tmp = 1e9;
    for (int i = 0; i < ans.size(); i++) if(ans[i].first < ans[0].first) swap(ans[i], ans[0]);

    
    sort(ans.begin(), ans.end(), [](pii a, pii b){ return min(a.first, a.second) < min(b.first, b.second);});
    int l = 0, r = n;
    auto check = [&](int mid) {
        if(!mid) return true;
        int res = 0;
        int flag = true;
        for (int i = 0; i < mid; i++) res += min(ans[i].first, ans[i].second);
        for (int i = 0; i < mid; i++) if(ans[i].first <= ans[i].second) flag = false;
        if(flag)
        {
            int ma = ans.front().first - ans.front().second;
            for (int i = 0; i < mid; i++) ma = min(ma, ans[i].first - ans[i].second);
            for (int i = mid; i < ans.size(); i++) ma = min(ma, ans[i].first - ans[mid-1].second);
            res += ma;
        }
        
        if(res <= c) return true;
        return false;
    };
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
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