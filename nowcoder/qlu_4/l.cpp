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
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int n, x, y, z, k, val;
void solve()
{
    cin >> n >> x >> y >> z >> k >> val;
    vector<PII> ans;
    rep(i, 1, n)
    {
        char tmp;
        int x1, y1, z1;
        cin >> x1 >> tmp >> y1 >> tmp >> z1;
        int fir = x1 * y * z + y1 * z + z1;
        cin >> x1 >> tmp >> y1 >> tmp >> z1;
        int sec = x1 * y * z + y1 * z + z1;
        ans.push_back({fir, sec});
    }
    sort(ans.begin(), ans.end(),
        [&](PII a, PII b){if(a.first == b.first) return a.second < b.second; else return a.first < b.first;  });
    int now = ans.front().second;
    int tmp = 0;
    rep(i, 1, ans.size()-1)
    {
        if(ans[i].first - now > k)
            tmp += ans[i].first - now - k;
        now = max(now, ans[i].second);
    }
    int end = now + k + 1;
    if(end > (x-1)*y*z + (y-1)*z + z) end = (x-1)*y*z + (y-1)*z + z;
    cout << (end - tmp - ans.front().first)* val << endl;
    // cout << tmp << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
