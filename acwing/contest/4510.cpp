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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int n, L, S;
    cin >> n >> L >> S;
    vector<PII> vec1;
    rep(i, 1, n)
    {
        int x, y; cin >> x >> y;
        vec1.push_back({x, y});
    }
    set<PII> st1;
    rep(i, 0, S)
        rep(j, 0, S)
        {
            int x; cin >> x;
            if(x) st1.insert({S-i, j});
        }
    int ans = 0;
    for(auto p:vec1)
    {
        int cnt = 0;
        bool ok = true;
        if(p.first+S>L || p.second+S>L) continue;
        for(auto p1:vec1)
        {
            p1.first -= p.first;
            p1.second -= p.second;
            if(p1.first >= 0 && p1.first <= S && p1.second >= 0 && p1.second <= S)
            {
                if(st1.count(p1)) cnt ++;
                else
                {
                    ok = false;
                    break;
                }
            }
        }
        if(ok && st1.size() == cnt) ans ++;
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