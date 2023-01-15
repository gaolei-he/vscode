/*
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
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    set<int> st;
    rep(i, 1, k) st.insert(a[i]);
    cout << *st.begin() << " ";
    vector<int> vec1;
    vec1.push_back(*st.rbegin());
    rep(i, k+1, n)
    {
        st.insert(a[i]);
        if(st.count(a[i-k])) st.erase(a[i-k]);
        cout << *st.begin() << " ";
        vec1.push_back(*st.rbegin());
    }
    cout << endl;
    for(auto i:vec1) cout << i << ' ';

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
*/
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
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    deque<PII> q;
    rep(i, 1, k)
    {
        while(q.size() && q.back().first < a[i]) q.pop_back();
        q.push_back({a[i], i});
    }
    vector<int> vec1, vec2;
    vec2.push_back(q.front().first);
    rep(i, k+1, n)
    {
        
        if(q.size() && q.front().second <= i-k) q.pop_front();
        while(q.size() && q.back().first < a[i]) q.pop_back();
        q.push_back({a[i], i});
        vec2.push_back(q.front().first);
    }
    q.clear();
    rep(i, 1, k)
    {
        while(q.size() && q.back().first >= a[i]) q.pop_back();
        q.push_back({a[i], i});
    }
    vec1.push_back(q.front().first);
    rep(i, k+1, n)
    {
        if(q.size() && q.front().second <= i-k) q.pop_front();
        while(q.size() && q.back().first >= a[i]) q.pop_back();
        q.push_back({a[i], i});
        vec1.push_back(q.front().first);
    }
    for(auto i:vec1) cout << i << ' ';
    cout << endl;
    for(auto i:vec2) cout << i << ' ';
    
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