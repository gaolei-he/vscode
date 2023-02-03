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
const int N = 10 + 5e4, mod = 1e9 + 7;
int n, q;
int b[N], t[N];
void solve()
{
    cin >> n >> q;
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, q) cin >> t[i];
    rep(i, 1, n) b[i] += b[i-1];
    rep(i, 1, q)
    {
        int k = t[i];
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(b[mid] > k) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;

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