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
const int N = 10 + 1e5, mod = 1e18 + 7;
void exgcd(int a, int b, int &g, int &x, int &y)
{
	if (!b)
	{
		g = a;
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, g, y, x);
	y -= a / b * x;
}
void solve()
{
    int a, b, ans, x, y, g;
    cin >> a >> b >> ans;
	exgcd(a, b, g, x, y);
	if(ans % g)
	{
		cout << -1 << endl;
		return;
	}
	a /= g, b /= g, ans /= g, x *= ans, y *= ans;
	int res = mod;
	auto f = [&](int t) {
		int r = x + b * t, s = y - a * t;
		if(r >= 0 && s >= 0) res = min(res, 2 * (r + s));
		else res = min(res, 2 * (abs(r) + abs(s)) - 1);
	};
	int t0 = -x / b;
	for(int i = t0-1;i<=t0+1;i++) f(i);
	t0 = y / a;
	for(int i = t0-1;i<=t0+1;i++) f(i);
	cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}