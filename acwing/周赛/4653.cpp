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
class Node
{
public:
    Node(){}
    Node(int k)
    {
        first = 0;
        second = k;
        while(k) first += k % 10, k /= 10;
    }
    int first;
    int second;
};
Node a[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) a[i] = Node(i);
    sort(a + 1, a + n + 1, [](Node a, Node b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    cout << a[m].second << endl;
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