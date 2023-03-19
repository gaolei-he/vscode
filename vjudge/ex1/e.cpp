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
const int N = 10 + 2e3, mod = 1e9 + 7;
vector<int> a;
int n, p;
bool check(int x)
{
    for (int i = 0; i < a.size(); i++)
    {
        auto it = upper_bound(a.begin(), a.end(), x);
        int val = it - a.begin();
        if((val - i) % p == 0) return false;
        x ++;
    }
    return true;
}
void solve()
{
    cin >> n >> p;
    a.resize(n);
    for(auto& x:a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> ans;
    rep(i, 0, 2000)
        if(check(i)) ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x:ans) cout << x << " ";
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