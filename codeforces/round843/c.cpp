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
#define lowbit(x) ((x)&(-(x)))
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, x;
    cin >> n >> x;
    if(x == n)
    {
        cout << x << endl;
        return;
    }
    else if(x > n)
    {
        cout << -1 << endl;
        return;
    }
    else if(x == 0)
    {
        while(n != lowbit(n)) n -= lowbit(n);
        cout << n * 2 << endl;
    }
    else
    {
        int tmp = n;
        while(tmp && tmp != x) tmp -= lowbit(tmp);
        if(tmp!=x)
        {
            cout << -1 << endl;
            return;
        }
        int tmpr = n - x;
        while(lowbit(tmpr) != tmpr) tmpr -= lowbit(tmpr);
        if(tmpr * 2 == lowbit(x))
        {
            cout << -1 << endl;
            return;
        }
        cout << x + tmpr * 2 << endl;

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