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
void solve()
{
    deque<int> q;
    int n, m;
    cin >> n >> m;
    int op;
    while(cin >> op)
    {
        int x;
        switch (op)
        {
        case 1: cin >> x; q.push_front(x); break;
        case 2: q.pop_front(); break;
        case 3: cin >> x; q.push_back(x); break;
        case 4: q.pop_back(); break;
        case 5: reverse(q.begin(), q.end()); break;
        case 6: cout << q.size() << endl; for(auto i:q) cout << i << ' '; cout << endl; break;
        case 7: sort(q.begin(), q.end()); break;
        
        default:
            break;
        }
    }
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