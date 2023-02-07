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
const int N = 10+2e5, mod = 1e9 + 7;
int a[N];
int p[N], s[N];
int n, q;
int f(int n)
{
    int res = 0;
    while(n) res += n % 10, n /= 10;
    return res;
}
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    cin >> n >> q;
    rep(i, 1, n+100) p[i] = i;
    rep(i, 1, n) cin >> a[i];
    while(q--)
    {
        int op, x, l, r;
        cin >> op;
        if(op & 1)
        {
            cin >> l >> r;
            for(int i=l;i<=r;)
            {
                a[i] = f(a[i]);
                if(a[i] < 10) p[i] = i + 1;
                if(find(i) == i) i ++;
                else i = p[i];
            }
        }
        else
        {
            cin >> x;
            cout << a[x] << endl;
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