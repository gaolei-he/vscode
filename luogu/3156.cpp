#include <iostream>
#define rep(i, a, n) for (int i=(a);i <= (n); ++i)
using namespace std;
int a[2000010];
int b[100010];
int main()
{
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    rep(i, 1, m) cout << a[b[i]] << endl;
    return 0;
}