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
const int N = 10 + 1e6, mod = 1e9 + 7;
char str[N];
int ne[N];
void solve()
{
    int n, cnt = 1;
    cin >> n;
    while(n)
    {
        cin >> str + 1;
        cout << "Test case #" << cnt++ << endl;
        for(int i=2, j=0;i<=n;i++)
        {
            while(j && str[j+1] != str[i]) j = ne[j];
            if(str[j+1] == str[i]) j++;
            ne[i] = j;
        }
        rep(i, 1, n)
        {
            if(i - ne[i] > ne[i] || i % (i - ne[i])) continue;
            cout << i << ' ' << i / (i - ne[i]) << endl;
        }
        cout << endl;
        cin >> n;
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