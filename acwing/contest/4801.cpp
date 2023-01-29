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
const int N = 30, mod = 1e9 + 7;
char str1[N], str2[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n * m + 1);
    cin >> str1 + 1 >> str2 + 1;
    rep(i, 1, n)
    {
        if(str1[i] == '>')
            rep(j, 1, m-1)
                g[m*(i-1)+j].push_back(m*(i-1)+j+1);
        else
            dec(j, m, 2)
                g[m*(i-1)+j].push_back(m*(i-1)+j-1);
    }
    rep(i, 1, m)
    {
        if(str2[i] == 'v')
            rep(j, 1, n-1)
                g[i+(j-1)*m].push_back(i+j*m);
        else
            dec(j, n, 2)
                g[i+(j-1)*m].push_back(i+(j-2)*m);
    }
    bool flag = true;
    bool sta[N];
    function<void(int)> dfs = [&](int st) {
        sta[st] = true;
        for(auto i:g[st])
        {
            if(sta[i]) continue;
            dfs(i);
        }
    };
    rep(i, 1, n*m)
    {
        memset(sta, 0, sizeof(sta));
        dfs(i);
        rep(i, 1, n*m) if(!sta[i]) flag = false;
        if(flag) continue;
        cout << "NO\n";
        return;
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