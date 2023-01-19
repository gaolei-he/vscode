#include <set>
#include <iostream>
#define int long long
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e5+10;
int p[N], sz[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int bomb[N];
signed main()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) p[i] = i, sz[i] = 1;
    int op = 0;
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        int a = find(u), b = find(v);
        if(a == b) continue;
        p[a] = b;
        sz[b] += sz[a];
    }
    rep(i, 1, n) cin >> bomb[i];
    set<int> st;
    rep(i, 1, n)
        if(bomb[i]) st.insert(find(i));

    int ans = 0;
    if(st.size() == 0)
    {
        rep(i, 1, n) st.insert(find(i));
        for(auto i:st) ans += sz[i] * sz[i];
    }
    else if(st.size() == 1) ans = sz[*st.begin()] * sz[*st.begin()];
    else ans = 0;
    cout << ans << endl;
    return 0;
}