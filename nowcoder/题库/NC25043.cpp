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
const int N = 10 + 1e5, mod = 1e9 + 7;
int t[N], d[N];
struct Node
{
    int d, t;
    double dt;
}a[N];
//脑袋卡壳了，直接算出来牛每秒毁坏的花，降序排列移走即可
void solve()
{
    int n, sum = 0;
    int val = 0;
    cin >> n;

    rep(i, 1, n)
    {
        cin >> a[i].t >> a[i].d;
        a[i].dt = a[i].d * 1.0 / a[i].t;
        val += a[i].d;
    }
    sort(a + 1, a + n + 1, [](Node a, Node b){
        return a.dt > b.dt;
    });
    rep(i, 1, n)
    {
        val -= a[i].d;
        sum += val * a[i].t * 2;
    }
    cout << sum << endl;


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