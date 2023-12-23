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
const int N = 10 + 2e6, mod = 1e9 + 7, P = 131;
ull h[2][N], p[N];
char str[2][N];
ull get(int l, int r, int op)
{
    return h[op][r] - h[op][l - 1] * p[r - l + 1];
}
void solve()
{
    int n; cin >> n;
    p[0] = 1;
    cin >> str[0] + 1;
    cin >> str[1] + 1;
    rep(i, 1, n) str[1][i + n] = str[1][i];
    rep(i, 1, n * 2)
    {
        char &op = str[1][i];
        if (op >= 'a') op -= 32;
        else op += 32;
    }
    rep(i, 1, n * 2)
    {
        p[i] = p[i - 1] * P;
        h[0][i] = h[0][i - 1] * P + str[0][i];
        h[1][i] = h[1][i - 1] * P + str[1][i];
    }
    // cerr << get(1, n, 0) << ' ' << get(4, 4 + n - 1, 1) << endl;
    rep(i, 1, n)
    {
        if(get(1, n, 0) == get(i, i + n - 1, 1))
        {
            cout << "Yes" << endl;
            i --;
            cout << min(i, n - i) << endl;
            return;
        }
    }
    cout << "No" << endl;

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