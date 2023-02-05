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
const int N = 10 + 3e5, mod = 1e9 + 7;
int legs[N];
vector<int> primes;
bool st[N];
int ans[N];
int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    rep(i, 2, N-5)
    {
        if(!st[i])
        {
            primes.push_back(i);
            for(int j=i+i;j<N;j+=i) st[j] = true;
        }
    }
    int n; cin >> n;
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> dividers;
    rep(i, 1, n)
    {
        cin >> legs[i];
        if(!ans[legs[i]]) ans[legs[i]] = i;
        else continue;
        int tmp = legs[i];
        int tmp1 = tmp;
        for(auto& j:primes)
        {
            if(tmp % j == 0) mp[j].push_back(tmp1), dividers[i].push_back(j);
            while(tmp%j==0) tmp/=j;
            if(tmp<=1) break;
        }
    }
    vector<vector<int>> g(N);
    rep(i, 1, N-4) p[i] = i;
    rep(i, 1, n)
    {
        for(auto j:dividers[i])
        {
            for(auto k:mp[j])
            {
                
            }
        }
    }
    int s, t; cin >> s >> t;
    s = legs[s];
    t = legs[t];
    dijkstra(s, t);
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