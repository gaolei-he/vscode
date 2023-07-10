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
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        int a = 4, b = 5;
        int c = 6, d = 7;
        int sm = a * c + b * d;
        int sm1 = 0;
        while(sm < x)
        {
            sm1 += a * c + b * d;
            c += 3, d += 3;
            a *= 10, b *= 10;
            sm += a * c + b * d;
        }
        if(sm - b * d >= x)
        {
            x -= sm1;
            int val = b - a + x / c;
            string s = "," + to_string(val) + "+" + to_string(val) + "=" + to_string(val + val);
            cout << s[x%c] << endl;
        }
        else
        {
            x -= sm1 + a * c;
            int val = b + x / d;
            string s = "," + to_string(val) + "+" + to_string(val) + "=" + to_string(val + val);
            cout << s[x%d] << endl;
        }
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