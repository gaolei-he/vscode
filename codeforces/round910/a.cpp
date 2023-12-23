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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnta = 0, cntb = 0;
    for(auto c : s) if(c == 'A') cnta ++; else cntb ++;
    if(cntb == k)
    {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') cnta --;
        else cntb --;
        if(cntb == k)
        {
            cout << i + 1 << ' ' << 'A' << endl;
            return;
        }
        else if(cntb + i + 1 == k)
        {
            cout << i + 1 << ' ' << 'B' << endl;
            return;
        }
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