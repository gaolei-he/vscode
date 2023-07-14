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
    vector<int> vec(n + 1);
    rep(i, 1, n) cin >> vec[i];
    string str; cin >> str;
    str = " " + str;
    vector<vector<int>> p(3, vector<int>(n+2, 0)), s(3, vector<int>(n+2, 0));
    rep(i, 1, n)
    {
        p[0][i] = p[0][i-1], p[1][i] = p[1][i-1], p[2][i] = p[2][i-1];
        if(str[i] == 'M')
            switch (vec[i])
            {
                case 0:p[0][i] ++; break;
                case 1:p[1][i] ++; break;
                case 2:p[2][i] ++; break;
                default: break;
            }
        
    }
    dec(i, n, 1)
    {
        s[0][i] = s[0][i+1], s[1][i] = s[1][i+1], s[2][i] = s[2][i+1];
        if(str[i] == 'X')
            switch (vec[i])
            {
                case 0:s[0][i] ++; break;
                case 1:s[1][i] ++; break;
                case 2:s[2][i] ++; break;
                default: break;
            }
        
    }
    int ans = 0;
    rep(i, 1, n)
    {
        if(str[i] == 'E')
        {
            
            rep(j, 0, 2)
            {
                rep(k, 0, 2)
                {
                    // cerr << i << ' ' << p[j][i-1] << ' ' << p[k][i+1] << endl;
                    set<int> st = {0, 1, 2, 3};
                    if(st.count(j)) st.erase(j);
                    if(st.count(k)) st.erase(k);
                    if(st.count(vec[i])) st.erase(vec[i]);
                    ans += p[j][i-1] * s[k][i+1] * (*st.begin());
                }
            }
            // cerr << ans << endl;
        }
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
