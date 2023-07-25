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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i=2;i <= x/i;i++)
        if(x % i == 0) return false;
    return true;
}
void solve()
{
    int n; cin >> n;
    int sm = 0;
    rep(i, 1, n)
    {
        int x; cin >> x;
        sm += x;
    }
    if(n == 1)
    {
        if(isPrime(sm)) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    else if(n == 2)
    {
        if(sm >= 4 and sm % 2 == 0 or isPrime(sm - 2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(n >= 3)
    {
        if(sm >= n * 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    // vector<int> vec;
    // rep(i, 1, 5000)
    //     if(isPrime(i))
    //         vec.push_back(i);
    // set<int> st = {2, 4};
    // rep(x, 6, 5000)
    // {
    //     for(auto i:vec)
    //         for(auto j:vec)
    //             if(i + j == x and x % 2 == 0)
    //                 st.insert(x);
    // }
    // cout << st.size() << endl;

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