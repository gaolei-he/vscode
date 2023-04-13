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
map<int, string> dic = {
    {0, ""},
    {1, "T"},
    {2, "B"},
    {3, "K"}
};
string f(string s)
{
    string res = "";
    reverse(s.begin(), s.end());
    dec(i, SZ(s)-1, 0)
    {
        if(s[i] == '0' && res.size() && res.back() != '0') res.push_back(s[i]);
        else if(s[i] == '0' && res.empty()) res.push_back(s[i]);
        else if(s[i] != '0')
        {
            res.push_back(s[i]);
            res = res + dic[i];
        }
    }
    while(res.back() == '0') res.pop_back();
    return res;
}
void solve()
{
    int n; cin >> n;
    string s = to_string(n);
    string ans = "";
    rep(i, 0, 2)
    {
        if(s.empty()) break;
        string tmp = s.substr(max(0ll, SZ(s)-4));
        rep(j, 0, 3)
            if(s.size()) s.pop_back();
        tmp = f(tmp);
        if(i == 1 && tmp.size()) tmp.push_back('W');
        // else if(i == 1) tmp.push_back('0');
        if(i == 2 && tmp.size()) tmp.push_back('Y');
        ans = tmp + ans;
    }
    while(ans.size() && ans.back() == '0') ans.pop_back();
    if(ans.size()) cout << ans << endl;
    else cout << "0\n";
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