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
#include <list>
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
class Node
{
public:
    int left;
    int right;
    int self;
    int defense;
    Node(int left, int right, int self, int defense)
    {
        this->left = left;
        this->right = right;
        this->self = self;
        this->defense = defense;
    }
};
void solve()
{
    // freopen("/home/mechrevo/Document/vscode/codeforces/edu_161/input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n), d(n);
    for(auto &x : a) cin >> x;
    for(auto &x : d) cin >> x;

    vector<int> attacks;
    vector<Node> vec;
    for (int i = 0; i < d.size(); i++)
    {
        int l = i - 1, r = i + 1;
        if(r >= n) r = -1;

        vec.emplace_back(l, r, i, d[i]);
        attacks.push_back(i);
    }

    rep(cnt, 1, n)
    {
        set<int> st;
        set<int> st1;
        int k = 0;
        for(auto idx : attacks)
        {
            int val = 0;
            if(vec[idx].left != -1) val = a[vec[idx].left];
            vec[idx].defense -= val;
            val = 0;
            if(vec[idx].right != -1) val = a[vec[idx].right];
            vec[idx].defense -= val;
        }
        for(auto idx : attacks)
        {
            if(vec[idx].defense < 0)
            {
                st1.insert(idx);
                int v1 = vec[idx].right;
                int v2 = vec[idx].left;
                if(vec[idx].left != -1) vec[vec[idx].left].right = v1;
                if(vec[idx].right != -1) vec[vec[idx].right].left = v2;
                if(v1 != -1) st.insert(v1);
                if(v2 != -1) st.insert(v2);
                k ++;
            }
            else
            {
                vec[idx].defense = d[idx];
            }
        }
        for(auto x : st1)
            if(st.count(x))
                st.erase(x);
        if(k) cout << k << ' ' << flush;
        else
        {
            rep(i, cnt, n) cout << "0 " << flush;
            cout << endl << flush;
            // exit(0);
            return;
        }
        attacks.clear();
        for(auto x : st) attacks.push_back(x);
        // for(auto x : attacks) cerr << x << ' ';
        // cerr << endl;
    }
    cout << endl;
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