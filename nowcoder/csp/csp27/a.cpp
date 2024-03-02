#include <iostream>
#include <vector>

#define rep(i, a, n) for(int i=(a);i<=(n);++i)
#define int long long

using namespace std;

signed main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> c(n + 1), b(n + 1);
    c[0] = 1;
    rep(i, 1, n) c[i] = c[i-1] * a[i];

    int val = 0;
    rep(i, 1, n)
    {
        b[i] = ((m % c[i]) - val) / c[i-1];
        cout << b[i] << ' ';
        val += c[i-1] * b[i];
    }

    return 0;
}