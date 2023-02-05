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
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> vec(n);
    unordered_map<int, int> mp;
    for(auto& v:vec)
    {
        int k; cin >> k;
        while(k--)
        {
            int x; cin >> x;
            mp[x] ++;
            v.push_back(x);
        }
    }
    for(auto& v:vec)
    {
        for(auto i:v) mp[i] --;
        bool flag = true;
        for(auto i:v) if(!mp[i]) flag = false;
        if(flag)
        {
            cout << "YES\n";
            return;
        }
        for(auto i:v) mp[i] ++;
    }
    cout << "NO\n";
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