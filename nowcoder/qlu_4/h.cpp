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
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
#define lowbit(x) ((x) & (-x))
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int tr[N * 4], n;
int a[N];
int add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        int t = 1;
        t += sum(a[i] / 2);
        add(a[i], t);
    }
    

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}