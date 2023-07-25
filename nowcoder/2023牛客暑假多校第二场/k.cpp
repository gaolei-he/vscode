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
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N], b[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    vector<int> vec;
    int ans = 0;
    rep(i, 1, n)
    {
        int val;
        if(b[i-1] == 0 and b[i] == 1)
        {
            val = 0;
            rep(j, i-1, mod)
            {
                if(b[j]) val ++;
                vec.push_back(a[j]);
                if(b[j] == 0 and b[j+1] == 0)
                {
                    cerr << val << endl;
                    sort(vec.begin(), vec.end());
                    while(val--)
                    {
                        ans += vec.back();
                        vec.pop_back();
                    }
                    i = j;
                    break;
                }
            }
        }
        else continue;

    }
    cout << ans << endl;
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