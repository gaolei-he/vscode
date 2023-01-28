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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int alice = a, bob = a;
    if(a == 0) cout << 1 << endl;
    else if(abs(b-c) <= a)
    {
        int ans = a + b + c;
        alice = a + b - c;
        bob = a - b + c;
        ans += min(min(alice, bob)+1, d);
        cout << ans << endl;
    }
    else
    {
        int ans = 0;
        ans = a + min(b, c) * 2 + a + 1;
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