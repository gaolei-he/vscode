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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e2, mod = 1e9 + 7;
int n, m;
int vec[N][N];
set<int> st;

int solve()
{
    cin >> n >> m;
    st.clear();
    memset(vec, 0, sizeof(vec));
    rep(i, 1, n*n) st.insert(i);
    bool ok = true;
    int xp = 0, yp = 0;
    bool ok1 = false;
    rep(i, 1, m)
    {
        int op, x, y, z;
        cin >> op >> x >> y;
        if(op == 1)
        {
            cin >> z;
            vec[x][y] = z;
            st.erase(z);
        }
        else if(ok) ok = false, xp = x, yp = y;
        else ok1 = true;
    }
    if(ok) return 1;
    else if(ok1) return -1;
    int ma = 0, mi = 1e9;
    rep(i, 1, n)
    {
        if(vec[xp][i] || i == yp) continue;
        vec[xp][i] = *st.begin();
        st.erase(*st.begin());
    }
    rep(i, 1, n) if(i != yp) ma = max(ma, vec[xp][i]);
    if(vec[xp][yp] && vec[xp][yp] < ma) return -1;
    if(vec[xp][yp] == 0)
    {
        auto it = st.lower_bound(ma);
        if(it == st.end()) return -1;
        vec[xp][yp] = *it;
        st.erase(*it);
    }

    rep(i, 1, n)
    {
        if(vec[i][yp]) continue;
        vec[i][yp] = *st.rbegin();
        st.erase(*st.rbegin());
    }
    rep(i, 1, n) if(i != xp) mi = min(vec[i][yp], mi);
    if(vec[xp][yp] > mi) return -1;
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            int x;
            if(vec[i][j]) x = vec[i][j];
            else st.erase(x = *st.begin());
            cout << x << ' ';

        }
        cout << endl;
    }

    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int k = solve();
        if(k == -1)
        {
            rep(i, 1, n)
            {
                rep(j, 1, n) cout << "0 ";
                cout << endl;
            }
        }
        else if(k == 1)
        {
            rep(i, 1, n)
            {
                rep(j, 1, n)
                {
                    int x = vec[i][j];
                    if(!x) st.erase(x = *st.begin());
                    cout << x << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}