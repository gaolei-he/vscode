#include <iostream>
#include <map>
#include <cstring>
#include <unordered_map>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e5+10;
int f[N], a[N];
int mp[N];
int main()
{
    int n; cin >> n;
    memset(mp, 0x3f, sizeof(mp));
    int cnt = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        f[i] = 1;
        int l = 1, r = cnt;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(mp[mid] > a[i]) r = mid - 1;
            else l = mid;
        }
        if(mp[r] < a[i]) f[i] = r + 1;
        else f[i] = 1;
        mp[f[i]] = min(mp[f[i]], a[i]);
        cnt = max(cnt, f[i]);
    }
    int ans = 0;
    rep(i, 1, n) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
/*
sync
fffaaaaa
*/