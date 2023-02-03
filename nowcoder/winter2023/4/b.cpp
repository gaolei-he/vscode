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
const int N = 10 + 1e5, mod = 1e9 + 7;
int c[N], b[N], a[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, n-1) cin >> c[i];
    
    rep(i, 0, n/2-1)
    {
        if(abs(c[i] - c[n-1-i]) % 2 == 0)
        {
            a[n-i-1] = a[i] = (c[i] + c[n-1-i]) / 2;
            b[i] = a[i] - c[i];
            b[n-i-1] = -b[i];
        }
        else
        {
            a[n-i-1] = a[i] = (m + c[i] + c[n-1-i]) / 2;
            b[i] = a[i] - c[i];
            b[n-i-1] = -b[i];
        }
        if((a[i] + b[i]) % m != c[i]) swap(b[i], b[n-i-1]);
    }
    if(m == 2)
    {
        rep(i, 0, n/2-1)
        {
            if(c[i] != c[n-1-i])
            {
                cout << "NO\n";
                return;
            }
            a[i] = c[i];
            a[n-i-1] = c[i];
        }
    }
    if(n & 1)
    {
        b[n/2] = 0;
        a[n/2] = c[n/2];
    }
    cout << "YES\n";
    rep(i, 0, n-1) cout << (a[i] % m + m) % m << (i == n - 1 ? "\n" : " ");
    rep(i, 0, n-1) cout << (b[i] % m + m) % m << (i == n - 1 ? "\n" : " ");
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