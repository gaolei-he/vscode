#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define int long long
#define ull unsigned long long
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
int vec[N];
void solve1()
{
    int n, m, d; cin >> n >> m >> d;
    rep(i, 1, n)
    {
        int x; cin >> x;
        vec[i] = x;
        tr.insert({x, i});
    }
    int sm = 0, tmp = m;
    for(auto &x : tr)
    {
        if(!tmp or x.first <= 0) break;
        sm += x.first;
        tmp--;
    }
    tmp = m - tmp;
    int ans = sm - d * n;
    dec(i, n, 0)
    {
        // cerr << ans << endl;
        if(i)tr.erase({vec[i], i});
        if(tr.order_of_key({vec[i], i}) < tmp)
        {
            sm -= vec[i];
            tmp--;
        }
        auto it = tr.find_by_order(tmp);
        while(tmp < m and it != tr.end() and it -> first > 0)
        {
            sm += it -> first;
            tmp++;
            it = tr.find_by_order(tmp);
        }
        if(i)ans = max(ans, sm - d * (i - 1));
    }
    cout << max(0ll, ans) << endl;
}
void solve2()
{
    int n, m, d;
    cin >> n >> m >> d;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0, sm = 0;
    rep(i, 1, n)
    {
        int x; cin >> x;
        if(x > 0 and pq.size() < m) pq.push(x), sm += x;
        else if(x <= 0) continue;
        else if(pq.size() == m and x > pq.top())
        {
            int val = pq.top();
            pq.pop();
            sm -= val;
            sm += x;
            pq.push(x);
        }
        ans = max(ans, sm - d * i);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve2();

    return 0;
}