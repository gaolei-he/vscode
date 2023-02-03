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
const double eps = 1e-4;
void solve()
{
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    // double length = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    // double si = abs(xa-xb) / length;
    // double co = abs(ya-yb) / length;
    double dx = abs(ya-yb) * 1.0 / 2;
    double dy = abs(xa-xb) * 1.0 / 2;
    if(xa > xb)
    {
        swap(xa, xb);
        swap(ya, yb);
    }
    double xc = (xa + xb) * 1.0 / 2;
    double yc = (ya + yb) * 1.0 / 2;
    if(xb > xa && yb <= ya)
    {
        double xd = xc + dx;
        double yd = yc + dy;
        if(fabs(round(xd) - xd) < eps && fabs(round(yd) - yd) < eps)
        {
            cout << (int)round(xd) << ' ' << (int)round(yd);

            return;
        }
        xd = xc - dx;
        yd = yc - dy;
        if(fabs(round(xd) - xd) < eps && fabs(round(yd) - yd) < eps)
        {
            cout << (int)round(xd) << ' ' << (int)round(yd);

            return;
        }
    }
    else
    {
        double xd = xc + dx;
        double yd = yc - dy;
        if(fabs(round(xd) - xd) < eps && fabs(round(yd) - yd) < eps)
        {
            cout << (int)round(xd) << ' ' << (int)round(yd);

            return;
        }
        xd = xc - dx;
        yd = yc + dy;
        if(fabs(round(xd) - xd) < eps && fabs(round(yd) - yd) < eps)
        {
            cout << (int)round(xd) << ' ' << (int)round(yd);
            return;
        }
    }
    cout << "No Answer!";

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