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
void solve()
{
    int x, y;
    cin >> x >> y;
    if(x * y < 0)
    {
        cout << (abs(x) + abs(y)) * 2 << endl;
        int op = 1;
        if(x < 0) op = -1;
        rep(i, 1, abs(x)) cout << op << " 0 ";
        if(y < 0) op = -1;
        rep(i, 1, abs(y)) cout << op << " 0 ";
        cout << endl;
    }
    else
    {
        cout << (x-y) * 2 << endl;
        rep(i, y, x) cout << i << ' ';
        dec(i, x-1, y+1) cout << i << ' ';
        cout << endl;
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