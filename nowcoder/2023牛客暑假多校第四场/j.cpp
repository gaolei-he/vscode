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
void solve(int n, int m)
{
    vector<int> vec(n);
    int ans = 0;
    function<void(int)> dfs = [&](int idx) {
        if(idx == n)
        {
            bool flag = true;
            rep(i, 0, n - 1)
                rep(j, i + 1, n - 1)
                {
                    int val = 0;
                    rep(k, i, j) val += vec[k];
                    if(val < 0) flag = false;
                }
            if(flag) ans ++;
            return;
        }
        rep(i, -m, m) vec[idx] = i, dfs(idx + 1);
    };
    dfs(0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
    rep(n, 1, 8)
        rep(m, 2, 2)
        {
            cout << n << ' ' << m << ' ';
            solve(n, m);
        }

    return 0;
}
/*
3 5 7 9 11
6 15 28 45 66
13 51 130 265 471
29 178 618 1595 3431
64 614 2904 9492 24718
*/