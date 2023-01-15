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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int w[26];
void solve()
{
    string s;
    cin >> s;
    int k; cin >> k;
    rep(i, 0, 25) cin >> w[i];
    rep(i, 1, k) s.push_back('#');
    int ans = 0;
    int ma = 0;
    rep(i, 0, 25) ma = max(ma, w[i]);
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '#') ans += ma * (i + 1);
        else ans += w[s[i]-'a'] * (i + 1);
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