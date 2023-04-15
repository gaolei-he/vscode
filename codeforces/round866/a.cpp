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
int f(string& s)
{
    char c = s.back();
    s.pop_back();
    if(c == '^')
    {
        if(s.empty()) return 1;
        else if(s.back() == '_') s.pop_back();
        else if(s.back() == '^')
        {
            s.pop_back();
            return 0;
        }
        if(s.empty()) return 1;
        else if(s.back() == '^') s.pop_back();
        else if(s.back() == '_') return 1;
        return 0;
    }
    else if(c == '_')
    {
        if(s.empty()) return 2;
        else if(s.back() == '^')
        {
            s.pop_back();
            return 1;
        }
        else if(s.back() == '_')
        {
            return 2;
        }
    }
    return 0;
}
void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '_')
        {
            if(i + 1 == s.size()) ans ++;
            else if(s[i + 1] == '_') ans ++;
        }
    }
    if(s.front() == '_' || s.size() == 1 && s.front() == '^') ans ++;
    cout << ans << endl;
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