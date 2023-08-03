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
const int N = 10 + 2e2, mod = 1e9 + 7;
char str[N][N];
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> str[i] + 1;
    int ans = 0;
    rep(i, 1, n)
        rep(j, 1, m)
        {
            bool flag = true;
            rep(k, 0, 3)
                rep(l, 0, 3)
                {
                    char op = '#';
                    if(k == 3 or l == 3) op = '.';
                    if(str[i + k][j + l] != op) flag = false;
                    op = '.';
                    if(k and l) op = '#';
                    if(str[i + k + 5][j + l + 5] != op) flag = false;
                }
            if(flag) cout << i << ' ' << j << endl;
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