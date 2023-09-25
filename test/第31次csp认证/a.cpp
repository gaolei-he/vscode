#include <iostream>
#include <vector>
#define int long long
#define endl "\n"
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
using namespace std;
void solve()
{
    int n, m; cin >> n >> m;
    int dx = 0, dy = 0;
    rep(i, 1, n)
    {
        int a, b; cin >> a >> b;
        dx += a, dy += b;
    }
    rep(i, 1, m)
    {
        int a, b; cin >> a >> b;
        cout << a + dx << ' ' << b + dy << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}