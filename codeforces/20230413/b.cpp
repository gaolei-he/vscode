// for _ in range(int(input())):
//     a, b, n = map(int, input().split())
//     if b >= a:
//         print(b * n)
//     elif b < a:
//         ans = (a + b) * (n // 2)
//         if n % 2 == 1:
//             ans += b
//         else:
//             ans -= a - b
//         print(ans)
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
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if(b >= a)
        cout << b * n << endl;
    else
    {
        int ans = (a + b) * (n / 2);
        if(n & 1) ans += b;
        else ans -= a - b;
        cout << ans << endl;
    }
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