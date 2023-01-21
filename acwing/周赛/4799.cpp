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
bool st[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n+1);
    rep(i, 1, m)
    {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int a = 0, b = 0, ansa = 0, ansb = 0;
    function<void(int, int, int)> dfs = [&](int v, int op, int cnt) {
        for(auto& e:vec[v])
            if(vec[e].size() == 1)
            {
                if(op == 1 && cnt > ansb) ansb = cnt;
                else if(op == 0 && cnt > ansa) a = e, ansa = cnt;
            }
            else if(!st[e])
            {
                st[e] = true;
                dfs(e, op, cnt+1);
                st[e] = false;
            }
    };
    st[1] = true;
    dfs(1, 0, 1);
    st[1] = false;
    st[a] = true;
    dfs(a, 1, 1);
    cout << ansb << endl;
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
/* simple mode
#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int main()
{

    return 0;
}
*/