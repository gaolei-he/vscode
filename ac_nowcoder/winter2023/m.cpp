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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
class A
{
public:
    int a, b;
    A(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    bool operator<(A& t)
    {
        double t1 = a * 1.0 / b;
        double t2 = t.a * 1.0 / t.b;
        return t1 < t2;
    }
    long double val()
    {
        return a * 1.0 / b;
    }
    A operator+(A& t)
    {
        int fenmu = this->b * t.b;
        int fenzi = this->b * t.a + this->a * t.b;
        int tmp = __gcd(fenmu, fenzi);
        fenzi /= tmp, fenmu /= tmp;
        return A(fenzi, fenmu);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    long double ans = 0;
    long double t = 1.0;
    vector<A> tmp;
    if(n >= m) rep(i, 1, m) ans += t / i;
    else
    {
        rep(i, 1, m) tmp.push_back(A(1, i));
        int k = m - n;
        while(tmp.size())
        {
            A t1 = tmp.back();
            tmp.pop_back();

            if(!k)
            {
                ans += t1.val();
                continue;
            }
            A t2 = tmp.back();
            tmp.pop_back();
            t1 = t1 + t2;
            k --;
            while(k && t1 < tmp[tmp.size()-2])
            {
                t2 = tmp.back();
                tmp.pop_back();
                t1 = t1 + t2;
                k --;
            }
            ans += t1.val();
        }
    }
    
    cout << fixed << setprecision(10) << ans << endl;
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