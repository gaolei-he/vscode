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
int tr[N], n, m;
char str[N];
int lowbit(int x) { return x & -x; }
void add(int x, int v)
{
    for (; x <= n; x += lowbit(x))
        tr[x] += v;
}
int sum(int x)
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += tr[x];
    return res;
}
void solve()
{
    cin >> n >> m;
    set<pii> st;
    cin >> str + 1;
    rep(i, 1, n) tr[i] = 0;
    rep(i, 1, n)
    {
        char op = str[i];
        add(i, op - 'a');
        add(i + 1, 'a' - op);
    }
    rep(i, 1, n)
    {
        if (i + 1 <= n and str[i] == str[i + 1]) st.insert({i, i + 1});
        if (i + 2 <= n and str[i] == str[i + 2]) st.insert({i, i + 2});
    }
    auto check = [&](pii p) {
        if (p.first >= 1 and p.second <= n and (sum(p.first) % 26) == (sum(p.second) % 26)) st.insert(p);
        else if(p.first >= 1 and p.second <= n and st.count(p)) st.erase(p);
    };
    while (m--)
    {
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op & 1)
        {
            cin >> x;
            x %= 26;
            add(l, x);
            add(r + 1, -x);
            pii p = {l - 1, l};
            check(p);
            p = {r, r + 1};
            check(p);
            p = {l - 2, l};
            check(p);
            p = {l - 1, l + 1};
            check(p);
            p = {r, r + 2};
            check(p);
            p = {r - 1, r + 1};
            check(p);
        }
        else
        {
            auto it = st.lower_bound({l, -1});
            if (it != st.end() and it->second <= r) cout << "NO\n";
            else cout << "YES\n";
        }

    }

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