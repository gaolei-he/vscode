#include <iostream>
#include <vector>

#define rep(i, a, n) for(int i=(a);i<=(n);++i)
#define dec(i, n, a) for(int i=(n);i>=(a);--i)
#define int long long
#define linf 0x3f3f3f3f3f3f3f3f

using namespace std;

signed main()
{
    int n, x; cin >> n >> x;
    vector<int> price(n + 1);
    rep(i, 1, n) cin >> price[i];
    int sm = 0;
    rep(i, 1, n) sm += price[i];
    int C = sm - x;
    vector<int> dp(C + 1);

    rep(i, 1, n)
        dec(j, C, price[i])
            dp[j] = max(dp[j], dp[j-price[i]]+price[i]);
        

    cout << sm - dp[C] << endl;


    return 0;
}