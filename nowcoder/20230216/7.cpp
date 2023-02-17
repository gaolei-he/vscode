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
    string s1 = "", s2 = "", a, b;
    cin >> a >> b;
    for(int i=1;i<a.size();i++)
        if(a[i] % 2 == a[i-1] % 2)
            s1 = s1 + max(a[i], a[i-1]);
    for(int i=1;i<b.size();i++)
        if(b[i] % 2 == b[i-1] % 2)
            s2 = s2 + max(b[i], b[i-1]);
    if(s1 == s2) cout << s1 << endl;
    else cout << s1 << endl << s2 << endl;
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