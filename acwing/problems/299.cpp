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
void remov(int x)
{
    cerr << st.size() << ' ';
    auto it = st.find(x);
    st.erase(it);
    cerr << st.size() << endl;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    deque<int> q;
    int sm = 0;
    
    for(int i=1, j=1;i<=n;i++)
    {
        sm += a[i];
        while(sm > m) sm -= a[j++];
        while(q.size() && q.front() < j)
        {
            remov(dp[q.front()] + a[q.pop_front(), q.front()]);
        }
        int last = 0;
        while(q.size() && a[q.back()] <= a[i])
        {
            remov(dp[q.back()] + a[last]);
            last = q.back();
            q.pop_back();
        }
        
        if(q.size()) dp[i] = dp[j - 1] + a[q.front()];
        if(st.size()) dp[i] = min(dp[i], *st.begin());
        if(q.size()) dp[i] = min(dp[i], dp[q.back()] + a[i]);
        // else dp[i] = min(dp[i], a[i]);

        q.push_back(i);
        st.insert(dp[i]);
    }
    cout << dp[n];
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