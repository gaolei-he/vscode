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
const int N = 10 + 2e5, mod = 1e9 + 7;
string str = "", ans = "";
int min_cost = 1e17+3;
int n, k;
void f(char x)
{
    string s = str;
    vector<int> p[19];
    for (int i = 0; i < s.size(); i++) p[s[i]-x+9].push_back(i);
    int cnt = 0, cost = 0;
    rep(i, 0, 9)
    {
        // cout << p[9+i].size() << endl;
        for(int j=0;j<p[9+i].size() && cnt < k;j++)
        {
            s[p[9+i][j]] = x;
            cnt ++;
            cost += i;
        }
        if(i)
        {
            for(int j=p[9-i].size()-1;j>=0 && cnt < k;j--)
            {
                s[p[9-i][j]] = x;
                cnt ++;
                cost += i;
            }
        }
    }
    // cout << cost << endl << s << endl;
    if(cost < min_cost) min_cost = cost, ans = s;
    else if(cost == min_cost && s < ans) ans = s;
}
void solve()
{
    cin >> n >> k;
    cin >> str;
    rep(i, 0, 9) f(i + '0');

    cout << min_cost << endl;
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