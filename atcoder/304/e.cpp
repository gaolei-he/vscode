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
const int N = 10 + 2e5, mod = 1e9 + 7;
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
    rep(i, 1, n) p[i] = i;
    rep(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        p[find(a)] = find(b);
    }
    set<string> st;
    int k; cin >> k;
    rep(i, 1, k)
    {
        int a, b;
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        st.insert(to_string(x) + " " + to_string(y));
    }
    int q; cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        if(st.count(to_string(x) + " " + to_string(y))) cout << "No\n";
        else if(st.count(to_string(y) + " " + to_string(x))) cout << "No\n";
        else cout << "Yes\n";
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