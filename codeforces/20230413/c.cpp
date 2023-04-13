#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
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
bool isPrime(int x)
{
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if((a + b + c) % 2 == 1)
        cout << "P" << endl;
    else if(a % 2 == 0 && b % 2 == 0)
        cout << "R" << endl;
    else
    {
        if((a == 0 || b == 0 || c == 0) && isPrime(a+b+c))
        {
            cout << "R" << endl;
            return;
        }
        else if(a == 0 || b == 0 || c == 0)
        {
            cout << "P" << endl;
            return;
        }
        else
        {
            int sm = 0;
            if(a % 2) sm += a;
            if(b % 2) sm += b;
            if(c % 2) sm += c;
            if(isPrime(sm))
            {
                cout << "R" << endl;
                return;}
        }
        int cnt = 0;
        if(isPrime(a+b)) cnt++;
        if(isPrime(a+c)) cnt++;
        if(isPrime(b+c)) cnt++;
        if(cnt >= 2)
            cout << "R" << endl;
        else
            cout << "P" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}