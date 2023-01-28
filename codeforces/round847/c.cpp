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
string f(int x)
{
    string res = "";
    while(x) res.push_back(x%10+'0'), x /= 10;
    reverse(res.begin(), res.end());
    return res;
}
void solve()
{
    int n; cin >> n;
    vector<vector<int>> vec(n, vector<int>(n-1));
    for(auto& v:vec)
        for(auto& x:v)
            cin >> x;
    
    unordered_set<string> str;
    for(auto& v:vec)
    {
        string ans = "";
        for(auto x:v) ans = ans + f(x) + ' ';
        str.insert(ans);
    }
    function<int(vector<int>&)> get = [&](vector<int>& v1) {
        unordered_set<int> st;
        rep(i, 1, n) st.insert(i);
        for(auto i:v1) st.erase(i);
        return *st.begin();
    };
    for(auto& v:vec)
    {
        int x = get(v);
        bool flag = true;
        for(auto i:v)
        {
            string tmp = f(x) + ' ';
            for(auto j:v) if(i != j) tmp = tmp + f(j) + ' ';
            if(str.count(tmp)) continue;
            else
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            string ans = f(x) + ' ';
            for(auto k:v) ans = ans + f(k) + ' ';
            cout << ans << endl;
            break;
        }
    }

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