#include <bits/stdc++.h>
#define rep(i, a, n) for (int i=(a); i<=(n); ++i)
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> a(n+1), s(n+1);
    rep(i, 1, n) cin >> a[i];
    if(n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    rep(i, 1, n) s[i] = s[i-1] + a[i];
    map<int, int> mp;
    rep(i, 1, n-1) mp[s[i]] ++;
    long long ans = 0;
    rep(i, 1, n-2)
    {
        mp[s[i]] --;
        if(mp[s[i]] == 0) mp.erase(s[i]);
        if(mp.count(s[i] * 2) && s[i] * 3 == s[n]) ans += mp[s[i]*2];
    }
    cout << ans << endl;

    return 0;
}