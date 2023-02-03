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
using pci = pair<char, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
char str[N];
int n, k;
vector<char> backstr, frontstr;
priority_queue<pci, vector<pci>, less<pci>> pq;
void f(int l, int r)
{
    if(backstr.size() + r - l + 1 <= k)
    {
        rep(i, l, r) backstr.push_back(str[i]);
        return;
    }
    int pos;
    while(-pq.top().second < l) pq.pop();
    pos = -pq.top().second;
    rep(i, l, pos-1) backstr.push_back(str[i]);
    frontstr.push_back(str[pos]);
    if(r+1<=n) pq.push({str[r+1], -(r+1)});
    f(pos+1, min(r+1, n));

}
void solve()
{
    cin >> n >> k;
    cin >> str + 1;
    if(k >= n-1)
    {
        sort(str+1, str+n+1, greater<char>());
        cout << str + 1 << endl;
        return;
    }
    rep(i, 1, k+1) pq.push({str[i], -i});
    f(1, k+1);
    sort(backstr.begin(), backstr.end(), greater<char>());
    for(auto i:frontstr) cout << i;
    rep(i, backstr.size()+frontstr.size()+1, n) cout << str[i];
    for(auto i:backstr) cout << i;
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