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
const int N = 10 + 4e6, mod = 1e9 + 7;
vector<int> primes;
void f()
{
    vector<bool> vec(N - 9, false);
    for (int i = 2; i < N - 10; i++)
    {
        if(!vec[i])
            primes.push_back(i);
            for(int j = 0; primes[j] <= (N - 10) / i; j++)
            {
                vec[primes[j] * i] = true;
                if(i % primes[j] == 0) break;
            }
    }
}
void solve()
{
    int n; cin >> n;
    for(auto x : primes)
    {
        if(x == 2) continue;
        cout << x << ' ';
        n --;
        if(!n) break;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}