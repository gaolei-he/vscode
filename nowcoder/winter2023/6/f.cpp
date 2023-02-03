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
#define lowbit(x) ((x)&(-(x)))
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
int f(int k)
{
    int res = 0;
    while(k) k -= lowbit(k), res ++;
    return res;
}
void solve()
{
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    vector<int> res;
    priority_queue<int, vector<int>, less<int>> pq;
    rep(i, 1, n) pq.push(a[i]);
    while(pq.size())
    {
        res.push_back(pq.top());
        int t = pq.top();
        pq.pop();
        t = f(t);
        if(t == 1) continue;
        pq.push(t);
    }
    while(q --)
    {
        int k; cin >> k;
        if(k < res.size()) cout << res[k] << endl;
        else cout << 1 << endl;
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