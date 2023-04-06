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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m; cin >> n >> m;
    map<int, int> mp;
    rep(i, 1, n)
    {
        int x; cin >> x;
        mp[x] = i;
    }
    vector<pii> vec;
    for(auto p:mp) vec.push_back(p);

    rep(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = b, b2;
        int l = 0, r = vec.size() - 1;
        int out = -1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(vec[mid].first >= b) r = mid;
            else l = mid + 1;
        }
        if(vec[l].first == b) b2 = 0, out = vec[l].first;
        else
        {
            b2 = (vec[l].first - b) * (vec[l].first - b);
            out = vec[l].first;
            if(l && b2 > (vec[l-1].first - b) * (vec[l-1].first - b)) b2 = (vec[l-1].first - b) * (vec[l-1].first - b), out = vec[l-1].first;
        }

        if(b2 - 4 * a * c < 0) cout << "YES\n" << out << endl;
        else if(b2 - 4 * a * c < 0) cout << "YES\n" << out << endl;
        else cout << "NO" << endl;
    }
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