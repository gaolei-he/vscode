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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    vector<int> vec1, vec2;
    vector<bool> vec(n, false);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x % 2) vec1.push_back(x);
        else vec2.push_back(x);
        if(x % 2 == 0) vec[i] = true;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    queue<int> q1, q2;
    for(auto x : vec1) q1.push(x);
    for(auto x : vec2) q2.push(x);
    vec1.clear();
    for(auto x : vec)
    {
        int val = -1;
        if(vec1.size()) val = vec1.back();
        if(x) vec1.push_back(q2.front()), q2.pop();
        else vec1.push_back(q1.front()), q1.pop();
        if(val > vec1.back())
        {
            cout << "No" << endl;
            return;
        }

    }
    cout << "Yes" << endl;
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