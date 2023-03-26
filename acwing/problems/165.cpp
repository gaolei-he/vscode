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
const int N = 20, mod = 1e9 + 7;
int car[N];
int ans = 20;
void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> vec(n);
    for(auto& x:vec) cin >> x;
    sort(vec.begin(), vec.end(), greater<int>());
    function<void(int, int)> dfs = [&](int u, int k) {
        if(k >= ans) return;
        else if(u == n)
        {
            ans = min(ans, k);
            return;
        }
        for (int i = 0; i <= k; i++)
        {
            if(car[i] + vec[u] <= w)
            {
                car[i] += vec[u];
                dfs(u + 1, k + (i == k ? 1 : 0));
                car[i] -= vec[u];
            }
        }
    };
    dfs(0, 0);
    cout << ans << endl;
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