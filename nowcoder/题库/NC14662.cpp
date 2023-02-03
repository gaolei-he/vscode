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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e4, mod = 1e9 + 7;
const double eps = 1e-4;
int n, k;
double w[N];
int v[N], c[N];
bool check(double x)
{
    rep(i, 1, n) w[i] = v[i] - c[i] * x;
    sort(w + 1, w + 1 + n, greater<double>());
    double sm = 0;
    rep(i, 1, k) sm += w[i];
    return sm > 0;
}
void solve()
{
    cin >> n >> k;
    rep(i, 1, n) cin >> c[i] >> v[i];
    double l = 0, r = N;
    while(fabs(r-l) > eps)
    {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)(l+eps) << endl;
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