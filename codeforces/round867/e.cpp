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
    int n; cin >> n;
    cin >> str + 1;
    vector<int> vec(26);
    rep(i, 1, n) vec[str[i] - 'a']++;
    for(auto x : vec)
        if(x > n / 2 or n & 1)
            return void(cout << -1 << endl);
    vec.clear();
    vec.resize(26, 0);
    rep(i, 1, n / 2)
    {
        if(str[i] == str[n-i+1])
            vec[str[i] - 'a']++;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int a = 0, b = 0;
    int v1 = 0, v2 = 0;
    for(auto x : vec)
        if(a <= b)
        {
            a += x;
            if(x) v1 ++;
        }
        else
        {
            b += x;
            if(x) v2 ++;
        }
    int ans = min(a, b);
    if(a > b and v1 > 1)
        ans += (a - b) / 2 + (a - b) % 2;
    else if(a > b and v1 == 1) ans += a - b;
    if(a < b and v2 > 1)
        ans += (b - a) / 2 + (b - a) % 2;
    else if(a < b and v2 == 1) ans += b - a;
    cout << ans << endl;
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