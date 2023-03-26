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
#define ll long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 11, mod = 1e9 + 7;
int a[N][N];
int dx[] = {0, 1};
int dy[] = {1, 0};
bool sta[N][N];
int h, w, ans, res;
unordered_set<int> st;
void dfs(int x, int y)
{

    if(x == h && y == w)
    {
        ans ++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx > 0 && tx <= h && ty > 0 && ty <= w && !sta[tx][ty])
        {
            if(st.count(a[tx][ty])) continue;
            st.insert(a[tx][ty]);
            sta[tx][ty] = true;
            dfs(tx, ty);
            sta[tx][ty] = false;
            st.erase(a[tx][ty]);
        }
    }
};
void solve()
{
    
    cin >> h >> w;
    rep(i, 1, h)
        rep(j, 1, w)
            cin >> a[i][j];
    
    sta[1][1] = true;
    st.insert(a[1][1]);
    dfs(1, 1);
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