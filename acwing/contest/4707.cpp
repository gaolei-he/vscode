#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define inf 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a);i<=(n);++i)
#define dec(i, n, a) for (int i=(n);i>=(a);--i)
using namespace std;
int main()
{
    int ans = 1000000;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    a[0] = a[n];
    rep(i, 1, n) ans = min(abs(a[i]-a[i-1]), ans);
    cout << ans << endl;

    return 0;
}