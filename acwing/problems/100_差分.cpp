// #include <iostream>
// using namespace std;

// const long long N = 1e5+10;
// long long a[N], s[N];
// int main()
// {
//     long long n;
//     cin >> n;
//     for(long long i=1;i<=n;i++) scanf("%lld", &a[i]);

//     for(long long i=1;i<=n;i++) s[i] = a[i] - a[i-1];

//     long long i = 2, j = n;
//     long long k = 0;
//     while(1)
//     {
//         while(s[i]<=0&&i<=n) i++;
//         while(s[j]>=0&&j>=2) j--;
//         long long tmp = s[i] + s[j];
        
        
//         if(j==1||i==n+1) break;
//         k += min(s[i], abs(s[j]));
//         if(tmp<0) s[j] = tmp, s[i] = 0;
//         else if(tmp==0) s[j] = s[i] = 0;
//         else s[i] = tmp, s[j] = 0;
        
//     }
//     long long tmp = k;
//     for(long long i=2;i<=n;i++) k += abs(s[i]);
//     tmp = k - tmp;
//     long long ans = tmp + 1;
//     cout << k << endl << ans;
//     return 0;
// }
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
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n)
    {
        int x; cin >> x;
        a[i] += x;
        a[i+1] -= x;
    }
    int ans1 = 0, ans2 = 0;
    rep(i, 2, n)
    {
        if(a[i] < 0) ans1 += abs(a[i]);
        else ans2 += a[i];
    }
    cout << max(ans1, ans2) << endl;
    ans1 = 0;
    rep(i, 2, n) ans1 += a[i];
    cout << abs(ans1) + 1 << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}