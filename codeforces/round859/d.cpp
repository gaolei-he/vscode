// def solve():
//     n, q = map(int, input().split())
//     a = [0] + list(map(int, input().split()))
//     s = [0 for i in range(len(a))]
//     for i in range(1, len(a)):
//         s[i] = s[i-1] + a[i]
//     for _ in range(q):
//         l, r, k = map(int, input().split())
//         sm = s[n] + (r - l + 1) * k - (s[r] - s[l-1])
//         if sm % 2 == 0:
//             print("NO")
//         else:
//             print("YES")
// for _ in range(int(input())):
//     solve()
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
const int N = 10 + 2e5, mod = 1e9 + 7;
int s[N], a[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    rep(i, 1, q)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int sm = s[n] + (r - l + 1) * k - (s[r] - s[l-1]);
        if(sm & 1) cout << "YES" << endl;
        else cout << "NO" << endl;
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