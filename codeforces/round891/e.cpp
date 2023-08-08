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
    int n, smr = 0, sml = 0; cin >> n;
    vector<int> vec1(n), vec2;
    for(auto &x : vec1) cin >> x, vec2.push_back(x), smr += x;
    sort(vec2.begin(), vec2.end());
    map<int, int> mp;
    rep(i, 0, n - 1)
    {
        sml += vec2[i];
        smr -= vec2[i];
        mp[vec2[i]] = (vec2[i] + 1) * (i + 1) - sml + smr - (vec2[i] - 1) * (n - 1 - i);
    }
    for(auto x : vec1) cout << mp[x] << ' ';
    cout << endl;
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