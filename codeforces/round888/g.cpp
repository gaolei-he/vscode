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
using ar3 = array<int, 3>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m; cin >> n >> m;
    int idx = 0;
    vector<pii> vec(m);
    vector<int> height(n);
    for(auto &x : height) cin >> x;
    for(auto &[x, y] : vec)
    {
        cin >> x >> y;
        x --, y --;
    }
    sort(vec.begin(), vec.end(), [&](pii a,pii b){
        return max(height[a.first], height[a.second]) < max(height[b.first], height[b.second]);
        });
    int q; cin >> q;
    vector<ar3> vec1(q), vec2;
    for(auto &[x, y, z] : vec1) 
    {
        cin >> x >> y >> z;
        x --, y --;
        vec2.push_back({x, y, z});
    }
    sort(vec1.begin(), vec1.end(), [&](ar3 a, ar3 b){return a[2] + height[a[0]] < height[b[0]] + b[2];});

    vector<int> fa(n);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x){return fa[x] == x ? x : fa[x] = find(fa[x]);};

    map<string, string> mp;
    for(auto &[x, y, z] : vec1)
    {
        // cerr << x << " " << z << endl;
        while(idx < m and max(height[vec[idx].first], height[vec[idx].second]) <= height[x] + z)
        {
            int fx = find(vec[idx].first), fy = find(vec[idx].second);
            if(fx != fy) fa[fx] = fy;
            idx ++;
        }
        if(find(x) == find(y)) mp[to_string(x) + " " + to_string(y) + " " + to_string(z)] = "YES";
        else mp[to_string(x) + " " + to_string(y) + " " + to_string(z)] = "NO";
    }
    for(auto &[x, y, z] : vec2)
        cout << mp[to_string(x) + " " + to_string(y) + " " + to_string(z)] << endl;


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
