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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    string a, b;
    cin >> a >> b;
    function<bool(void)> check = [&]() {
        int r1 = 0, r2 = 0;
        for(auto i:a) r1 = r1 * 2 + (i - '0');
        for(auto i:b) r2 = r2 * 3 + (i - '0');
        if(r1 == r2)
        {
            cout << r1 << endl;
            return true;
        }
        return false;
    };
    for(auto& i:a)
    {
        int t = i;
        if(i=='0') i = '1';
        else i = '0';
        for(auto& j:b)
        {
            int u = j;
            set<char> st = {'0', '1', '2'};
            st.erase(u);
            for(auto k:st)
            {
                j = k;
                if(check()) return;
            }
            j = u;
        }
        i = t;
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