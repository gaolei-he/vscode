#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
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
const int N = 20, mod = 1e9 + 7;
int g[N][N];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    int ans = 0;
    do {
        int sm = 0;
        for (int i = 0; i < vec.size() - 1; i++) {
            int u = vec[i], v = vec[i + 1];
            if(!g[u][v]) {
                ans = max(sm, ans);
                sm = 0;
            }
            sm += g[u][v];
        }
        ans = max(sm, ans);
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
    solve();

    return 0;
}