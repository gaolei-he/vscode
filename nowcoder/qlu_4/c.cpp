#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<random>
#include<cassert>
#include<functional>
#include<iomanip>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i,a,n) for(int i = (a);i <= (n);i++)
#define dec(i,n,a) for(int i = (n);i >= (a);i--)
using namespace std;
using PII = pair<int,int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int N =10 + 2e5 ,mod=1e9 + 7;
void solve()
{
    int n, m, q;
    cin >> n >> m;
    cin >> q;
    while (q--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int ma = max(x, y);
        double x1 = n * 1.0 / x, y1 = m * 1.0 / y;
        int times = ceil(min(x1, y1));
        cout << k / times + 1 << ' ' << 1 + k % times * x << ' ' << 1 + k % times * y << endl;
    }
    

}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();

    return 0;
}