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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    string s; cin >> s;
    int n = SZ(s);
    int op = 0, idx = n - 1;
    dec(i, n - 1, 0)
    {
        if(op) s[i]++;
        if(s[i] > '9') s[i] = '0';
        else op = 0;
        if(s[i] < '5') continue;
        s[i] = '0';
        idx = i;
        op = 1;
    }
    if(op) cout << 1;
    rep(i, 0, idx) cout << s[i];
    rep(i, idx + 1, n - 1) cout << 0;
    cout << endl;
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