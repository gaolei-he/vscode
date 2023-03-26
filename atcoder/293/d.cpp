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
const int N = 10 + 4e5, mod = 1e9 + 7;
int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n*2) p[i] = i;
    int ans = 0;
    for(int i=1;i<=2*n;i+=2) p[find(i)] = find(i + 1);
    unordered_set<int> st;
    rep(i, 1, m)
    {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a = a * 2 - 1;
        c = c * 2 - 1;
        if(b == 'B') a ++;
        if(d == 'B') c ++;
        int e = find(a), f = find(c);
        if(e == f) ans ++, st.insert(e);
        else p[e] = f;
    }
    int ans1 = 0;
    unordered_set<int> st1;
    rep(i, 1, n * 2) if(!st.count(find(i))) st1.insert(find(i));
    cout << ans << ' ' << SZ(st1) << endl;
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