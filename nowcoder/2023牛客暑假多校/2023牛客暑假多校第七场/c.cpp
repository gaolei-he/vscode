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
    int n, k;
    cin >> n >> k;
    vector<int> vec(n-1);
    for(auto &x : vec) cin >> x;
    int cnt = 0;
    vector<int> ans;
    int st = 0;
    while(cnt < k)
    {
        if(st > 1e3)
        {
            cout << -1 << endl;
            return;
        }
        bool flag = true;
        ans.clear();
        ans.push_back(st);
        st ++;
        for(auto x : vec)
        {
            if(ans.back() > (ans.back() xor x)) flag = false;
            ans.push_back(ans.back() xor x);
        }
        if(flag) cnt ++;
    }
    for(auto x : ans) cout << x << ' ';
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