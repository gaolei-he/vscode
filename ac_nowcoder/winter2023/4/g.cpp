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
const int N = 10 + 8e2, mod = 1e9 + 7;
char str[N][N];
bool st[N][N];
string f(int x, int y)
{
    string s;
    while(x) s.push_back(x%10+'0'), x /= 10;
    s.push_back(' ');
    while(y) s.push_back(y%10+'0'), y /= 10;
    return s;
}
void g(int& x, int& y, string ans)
{
    x = 0;
    y = 0;
    while(ans.back() != ' ')
    {
        y *= 10;
        y += ans.back() - '0';
        ans.pop_back();
    }
    ans.pop_back();
    while(ans.size())
    {
        x *= 10;
        x += ans.back() - '0';
        ans.pop_back();
    }
}
void solve()
{
    int n, m, xs, ys, q;
    cin >> n >> m >> xs >> ys >> q;
    xs ++, ys ++;
    rep(i, 1, n) cin >> str[i] + 1;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    vector<set<string>> vec;
    vec.push_back({f(xs, ys)});
    set<string> total;
    bool flag = false;
    auto func = [&]()
    {
        set<string> st1;
        int val = total.size();
        for(auto tmp:vec[vec.size()-1])
        {
            int x, y;
            g(x, y, tmp);
            rep(i, 0, 3)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx < 1 || ty < 1 || tx > n || ty > m || str[tx][ty] == '#') continue;
                st1.insert(f(tx, ty));
                total.insert(f(tx, ty));
            }
            st1.insert(f(x, y));
            total.insert(f(x, y));
        }
        
        vec.push_back(st1);
        if(val == total.size())
            flag = true;
    };
    while(q --)
    {
        int xt, yt;
        bool res = true;
        cin >> xt >> yt;
        xt ++, yt ++;
        rep(i, 1, mod)
        {
            if(i >= vec.size() - 1) func();
            switch (str[xt][yt])
            {
            case 'L':if(str[xt][yt-1] != '#') yt --; break;
            case 'R':if(str[xt][yt+1] != '#') yt ++; break;
            case 'U':if(str[xt-1][yt] != '#') xt --; break;
            case 'D':if(str[xt+1][yt] != '#') xt ++; break;
            default: break;
            }
            if(vec[i].count(f(xt, yt)))
            {
                cout << i << endl;
                res = false;
                break;
            }
            if(flag) break;
        }
        if(res) cout << -1 << endl;

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