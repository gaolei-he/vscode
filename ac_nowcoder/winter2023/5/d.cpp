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
pii sa[N], sy[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> sa[i].first >> sa[i].second;
    rep(i, 1, n) cin >> sy[i].first >> sy[i].second;
    priority_queue<pii, vector<pii>, greater<pii>> pq1, pq2;
    int r1 = 0, r2 = 0;
    rep(i, 1, n)
    {
        if(sa[i].first <= r1+1) r1 = max(r1, sa[i].second);
        else pq1.push(sa[i]);
        if(sy[i].first <= r2+1) r2 = max(r2, sy[i].second);
        else pq2.push(sy[i]);
        while(pq1.size() && pq1.top().first <= r1 + 1)
        {
            auto t = pq1.top();
            pq1.pop();
            r1 = max(r1, t.second);
        }
        while(pq2.size() && pq2.top().first <= r2 + 1)
        {
            auto t = pq2.top();
            pq2.pop();
            r2 = max(r2, t.second);
        }
        
        if(r1 == r2) cout << "win_win!" << endl;
        else if(r1 > r2) cout << "sa_win!" << endl;
        else cout << "ya_win!" << endl;
        cout << max(r1, r2) - min(r1, r2) << endl;
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