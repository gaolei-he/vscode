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
const int N = 10 + 1e3, mod = 1e9 + 7;
int p[N], sz[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n, d; cin >> n >> d;
    rep(i, 1, n) p[i] = i, sz[i] = 1;
    int c = 0;
    int ans = 0;
    rep(i, 1, d)
    {
        int x, y; cin >> x >> y;
        int a = find(x), b = find(y);
        if(a == b) c++;
        else p[a] = b, sz[b] += sz[a];
        priority_queue<int, vector<int>, less<int>> q;
        unordered_set<int> tmp;
        rep(i, 1, n) tmp.insert(find(i));
        for(auto i:tmp) q.push(sz[i]);
        ans = 0;
        rep(i, 1, c + 1)
        {
            ans += q.top();
            q.pop();
            if(q.empty()) break;
        }
        cout << ans - 1 << endl;
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