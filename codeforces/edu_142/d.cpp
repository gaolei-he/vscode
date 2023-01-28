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
const int N = 10 + 1e5, mod = 1e9 + 7;
string f[] = {"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 "};
map<int, int> ans;
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) ans[i] = 0;
    vector<vector<int>> vec(n+1);
    unordered_map<string, unordered_set<int>> st;
    rep(i, 1, n)
    {
        string t = "";
        rep(j, 1, m)
        {
            int x; cin >> x;
            vec[i].push_back(x);
            t = t + f[x];
            st[t].insert(i);
        }
    }
    vector<string> str;
    rep(i, 1, n)
    {
        auto& v = vec[i];
        string t[m], tmp = "";
        for (int i = 0; i < v.size(); i++) t[v[i]-1] = f[i+1];
        for(auto i:t) tmp += i;
        str.push_back(tmp);
    }
    while(m)
    {
        for(auto& tmp : str)
        {
            vector<int> era;
            if(st.count(tmp))
                for(auto i:st[tmp])
                {
                    if(ans[i]) era.push_back(i);
                    ans[i] = max(ans[i], m);
                }
            auto& st1 = st[tmp];
            for(auto i:era) st1.erase(i);
            tmp.pop_back();
            while(tmp.back() != ' ' && tmp.size()) tmp.pop_back();
        }
        m --;
    }
    
    rep(i, 1, n) cout << ans[i] << ' ';
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