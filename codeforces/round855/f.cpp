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
using pss = pair<string, string>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for(auto& s:vec) cin >> s;
    int ans = 0;
    string str = "abcdefghijklmnopqrstuvwxyz";
    reverse(vec.begin(), vec.end());
    map<pss, int> mp;
    for(auto& s:vec)
    {
        string tmp = "";
        if(SZ(tmp) % 2) tmp = "1" + tmp;
        unordered_map<char, int> mp1;
        for(auto c:s) mp1[c] ++;
        for(auto c:str)
            if(mp1.count(c)) tmp.push_back((mp1[c]%2?'1':'0'));
            else tmp.push_back('0');
        string tmpsec = "";
        for(auto&[k, v]:mp1) tmpsec.push_back(k);

        string tmp1 = "";
        for(auto c:tmp)
            if(c == '0') tmp1.push_back('1');
            else tmp1.push_back('0');
        for (int i = 0; i < str.size(); i++)
        {
            if(mp1.count(str[i])) continue;
            
        }
        
        mp[{tmp, tmpsec}] ++;
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