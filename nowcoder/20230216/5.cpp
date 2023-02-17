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
    char s[6];
    rep(i, 0, 5)
    {
        char c; cin >> c;
        s[i] = c;
    }
    set<char> st[6];
    rep(i, 0, 5) st[i].insert(s[i]);
    // rep(i, 0, 5) cerr << s[i] << ' ';
    int n; cin >> n;
    rep(i, 1, n)
    {
        rep(j, 0, 5)
        {
            char c = '6';
            for(;;c--) if(st[j].find(c) == st[j].end()) break;
            st[j].insert(c);
            s[j] = c;
        }
    }
    rep(i, 0, 5) cout << s[i] << (i==5?"\n":" ");
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