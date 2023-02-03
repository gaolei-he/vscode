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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

const int N = 10 + 1e5, mod = 1e9 + 7;
int cnt[N];
int a[N];
void solve()
{
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    int n; cin >> n;
    int tn = n;
    rep(i, 1, n) cin >> a[i];
    vector<set<int>> vec(n+1);
    vector<int> ans;
    rep(i, 1, n)
    {
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(vec[mid].count(a[i])) l = mid + 1;
            else r = mid;
        }
        vec[l].insert(a[i]);
    }
    rep(i, 1, n) cnt[i] = vec[i].size();
    dec(i, tn, 1)
    {
        n -= cnt[i+1];

        if(cnt[i+1]) ans.push_back(n - cnt[i+1]);
        else ans.push_back(tn);
    }
    dec(i, tn-1, 0) 
        cout << ans[i] << endl;

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