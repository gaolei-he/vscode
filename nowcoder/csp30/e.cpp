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
    int n; cin >> n;
    string t; cin >> t;
    vector<string> vec(n);
    for(auto& s : vec) cin >> s;
    int res = linf;
    vector<string> tmp;
    function<void(int, int)> dfs = [&](int idx, int no)
    {
        if(idx >= n)
        {
            set<char> st;
            for(auto c : t) st.insert(c);
            char op = '$';
            int mi = 0;
            for(auto& s : tmp)
            {
                if(op == '$') op = s.back();
                else if(op != s.front()) return;
                op = s.back();
                for(auto c : s) if(st.count(c))st.erase(c);
                mi += s.size() - 1;
            }
            if(tmp.front().front() != tmp.back().back()) return;
            for(auto s : tmp) cerr << s << endl;
            cerr << mi << endl;
            if(st.empty()) res = min(res, mi);
            return;
        }
        tmp.push_back(vec[idx]);
        rep(j, idx + 1, n)
        {
            if(j == no) continue;
            dfs(j, no);
        }
        tmp.pop_back();
    };
    rep(i, 0, n - 1)
    {
        int ans = linf;
        res = linf;
        tmp.push_back(vec[i]);
        rep(j, 0, n)
        {
            if(j == i) continue;
            dfs(j, i);
        }
        tmp.pop_back();
        cout << res << endl;
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