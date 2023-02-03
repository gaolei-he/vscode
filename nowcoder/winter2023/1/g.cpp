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
const int N = 10 + 1e5, mod = 1e9 + 7;
int f(int k)
{
    return round(10 * sqrtl(k));
}
int sm = 0;

int a[N];

void solve()
{
    int n, m; cin >> n >> m;
    set<int> st;
    rep(i, 1, n) st.insert(i);
    rep(i, 1, n)
    {
        cin >> a[i];
        sm += a[i];
    }
    int op;
    rep(i, 1, m)
    {
        cin >> op;
        if(op == 2) cout << sm << endl;
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            auto it = st.lower_bound(l);
            vector<int> vec;
            for(;;++it )
            {
                if((*it)>r || it == st.end()) break;
                int t = *it;
                int tmp = k;
                bool flag = false;
                while(tmp--)
                {
                    sm -= a[t];
                    a[t] = f(a[t]);
                    sm += a[t];
                    if(a[t] == 0 || a[t] == 99 || a[t] == 100)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag) vec.push_back(*it);
            }
            for(auto i:vec) st.erase(i);

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