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
const int N = 10 + 2e5, mod = 1e9 + 7;
char str[N];
void solve()
{
    int n, q; cin >> n >> q;
    cin >> str + 1;
    int ans = 0;
    while(q--)
    {
        int l, r; cin >> l >> r;
        string x; cin >> x;
        reverse(x.begin(), x.end());
        int tl = l, tr = r;
        l = min((ans ^ tl) % n + 1, (ans ^ tr) % n + 1);
        r = max((ans ^ tl) % n + 1, (ans ^ tr) % n + 1);
        // cerr << l << ' ' << r << endl;
        rep(i, l, r)
        {
            if(str[i] == 'A')
            {
                for(auto &c : x)
                    if(c == '0') c = '1';
                    else c = '0';
            }
            else
            {
                for(auto &c : x)
                    if(c == '0')
                    {
                        c = '1';
                        break;
                    }
                    else
                        c = '0';
            }
            // cerr << x << endl;
        }
        int v = 1;
        ans = 0;
        for(auto c : x)
        {
            ans += (c - '0') * v;
            v *= 2;
        }
        reverse(x.begin(), x.end());
        cout << x << endl;
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