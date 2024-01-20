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
#include <regex>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
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
    int n; cin >> n;
    n -= 1;
    int m = __lg(n);
    cout << m + 1 << endl;
    vector<vector<int>> vec(m + 1);
    rep(i, 1, n)
    {
        rep(j, 0, m)
            if((i >> j) & 1)
                vec[j].push_back(i);
    }
    string ans;
    rep(i, 0, m)
    {
        cout << vec[i].size() << ' ';
        for(auto x : vec[i]) cout << x + 1 << ' ';
        cout << endl;
    }
    cin >> ans;
    set<int> st1, st2;
    rep(i, 1, n) st1.insert(i);
    rep(i, 0, m)
    {
        char c = ans[i];
        if(c == '1')
        {
            st2.clear();
            for(auto x : vec[i]) if(st1.count(x)) st2.insert(x);
            swap(st1, st2);
            st2.clear();
        }
        else
        {
            for(auto x : vec[i]) if(st1.count(x)) st1.erase(x);
        }
    }
    cout << *st1.begin() + 1 << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // int t; cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}