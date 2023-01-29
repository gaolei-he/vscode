#include <iostream>
#include <cstring>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int a[40];
int f[500010];
int main()
{
    int n, x;
    cin >> n >> x;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    rep(i, 1, n) cin >> a[i];
    int ans = 0;
    rep(i, 1, n)
        dec(j, x, 0)
            f[j] = min(f[j], f[max(j-a[i], 0)]+a[i]);
    cout << f[x] << endl;
    return 0;
}