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
void solve()
{
    string s;
    cin >> s;
    if(s.size() & 1)
    {
        rep(i, 0, s.size()/2) cout << '4';
        rep(i, 0, s.size()/2) cout << '7';
    }
    else
    {
        string ans = "";
        rep(i, 1, s.size()/2) ans.push_back('7');
        rep(i, 1, s.size()/2) ans.push_back('4');
        if(ans < s)
        {
            reverse(ans.begin(), ans.end());
            cout << '4' << ans << '7';
        }
        else
        {
            reverse(ans.begin(), ans.end());
            do
            {
                if(ans >= s)
                {
                    cout << ans;
                    break;
                }
            } while (next_permutation(ans.begin(), ans.end()));
            
        }

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