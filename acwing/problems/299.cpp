#include <iostream>
#include <cstring>
#include <algorithm>
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
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[N], dp[N];
multiset<int> st;
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        if(a[i] > m)
        {
            cout << -1 << endl;
            return;
        }
    }
    deque<int> q;
    int sm = 0;
    for(int i=1, j=1;i<=n;i++)
    {
        sm += a[i];
        while(sm > m) sm -= a[j ++];
        while(q.size() && q.front() < j)
        {
            int t = q.front();
            q.pop_front();
            if(q.size()) st.erase(st.find(dp[t] + a[q.front()]));
        }
        while(q.size() && a[q.back()] <= a[i])
        {
            int t = q.back();
            q.pop_back();
            if(q.size()) st.erase(st.find(dp[q.back()] + a[t]));
        }
        if(q.size()) st.insert(dp[q.back()] + a[i]);
        q.push_back(i);
        dp[i] = dp[j-1] + a[q.front()];
        if(st.size()) dp[i] = min(dp[i], *st.begin());
    }
    cout << dp[n] << endl;
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