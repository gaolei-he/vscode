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
void solve()
{
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> price(N, vector<int>(K));
    for(auto& vec:price) for(auto& val:vec) cin >> val;
    int ans = linf;
    vector<vector<int>> lines(M, vector<int>(K * K + 2));
    for(auto& vec:lines) for(auto& val:vec) cin >> val;
    vector<int> line(N);
    function<void(int)> dfs = [&](int cnt)
    {
        if(cnt == N)
        {
            int sm = 0;
            for(auto& vec : lines)
            {
                int l = vec[0], r = vec[1];
                int p1 = line[l], p2 = line[r];
                sm += vec[p1 * K + p2 + 2];
            }
            rep(i, 0, N - 1) sm += price[i][line[i]];
            ans = min(ans, sm);
            return;
        }
        for(int i = 0; i < K; i++)
        {
            line[cnt] = i;
            dfs(cnt + 1);
        }
    };
    dfs(0);
    cout << ans << endl;
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