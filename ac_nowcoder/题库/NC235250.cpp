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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e6, mod = 1e9 + 7;
bool st[N];

void solve()
{
    string a;
    cin >> a;
    int n; cin >> n;
    string b[n];
    rep(i, 0, n-1) cin >> b[i];
    vector<int> dic[26];
    rep(i, 0, n-1) dic[b[i].back()-'a'].push_back(i);

    vector<int> tmp;
    while(a.size())
    {
        char c = a.back();
        a.pop_back();
        for(auto i:dic[c-'a'])
        {
            if(b[i].size()) b[i].pop_back();
            if(!b[i].size()) continue;
            if(b[i].back() == c) tmp.push_back(i);
            else dic[b[i].back()-'a'].push_back(i);
        }
        dic[c-'a'].clear();
        for(auto i:tmp) dic[c-'a'].push_back(i);
        tmp.clear();

    }
    rep(i, 0, n-1) cout << (b[i].size() ? "No" : "Yes") << endl;


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