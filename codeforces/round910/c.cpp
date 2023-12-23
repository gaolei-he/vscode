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
    int n, m, k;
    cin >> n >> m >> k;
    if(k < n + m - 2)
    {
        cout << "NO" << endl;
        return;
    }
    else if((k - (n - 2) - (m - 2)) % 4 == 2)
    {
        vector<vector<char>> vec1(n, vector<char>(m - 1));
        vector<vector<char>> vec2(n - 1, vector<char>(m));
        vec1[n - 1][m - 2] = 'R';
        vec1[n - 2][m - 2] = 'R';
        vec2[n - 2][m - 1] = 'B';
        vec2[n - 2][m - 2] = 'B';
        dfs(n - 1, m - 1);
        for(auto &vec : vec1)
        {
            for(auto c : vec) cout << c << ' ';
            cout << endl;
        }
        for(auto &vec : vec2)
        {
            for(auto c : vec) cout << c << ' ';
            cout << endl;
        }
    }
    else if((k - (n - 2) - (m - 2)) % 2 == 0)
    {
        vector<vector<char>> vec1(n, vector<char>(m - 1));
        vector<vector<char>> vec2(n - 1, vector<char>(m));
        vec1[n - 1][m - 2] = 'R';
        vec1[n - 2][m - 2] = 'R';
        vec2[n - 2][m - 1] = 'B';
        vec2[n - 2][m - 2] = 'B';
        if(n > m)
        {
            
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