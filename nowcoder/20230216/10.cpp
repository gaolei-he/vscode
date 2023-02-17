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
const int N = 10 + 1e5, mod = 1e9 + 7;
class Node
{
public:
    int h1, m1, s1, h2, m2, s2;
    int b()
    {
        return h2 * 10000 + m2 * 100 + s2;
    }
    int f()
    {
        return h1 * 10000 + m1 * 100 + s1;
    }
    string pb()
    {
        string res = "";
        if(h2 < 10) res += '0', res += h2 + '0';
        else res += h2 / 10 + '0', res += h2 % 10 + '0';
        res += ':';
        if(m2 < 10) res += '0', res += m2 + '0';
        else res += m2 / 10 + '0', res += m2 % 10 + '0';
        res += ':';
        if(s2 < 10) res += '0', res += s2 + '0';
        else res += s2 / 10 + '0', res += s2 % 10 + '0';
        return res;
    }
    string pf()
    {
        string res = "";
        if(h1 < 10) res += '0', res += h1 + '0';
        else res += h1 / 10 + '0', res += h1 % 10 + '0';
        res += ':';
        if(m1 < 10) res += '0', res += m1 + '0';
        else res += m1 / 10 + '0', res += m1 % 10 + '0';
        res += ':';
        if(s1 < 10) res += '0', res += s1 + '0';
        else res += s1 / 10 + '0', res += s1 % 10 + '0';
        return res;
    }
};

void solve()
{
    int n; cin >> n;
    vector<Node> vec(n);
    for(auto& x:vec)
    {
        int h1, m1, s1, h2, m2, s2;
        scanf("%lld:%lld:%lld - %lld:%lld:%lld", &h1, &m1, &s1, &h2, &m2, &s2);
        x = {h1, m1, s1, h2, m2, s2};
    }
    sort(vec.begin(), vec.end(), [&](Node a, Node b) {
        if(a.h1 != b.h1) return a.h1 < b.h1;
        else if(a.m1 != b.m1) return a.m1 < b.m1;
        else return a.s1 < b.s1;
    });
    Node tmp = {0, 0, 0, 0, 0, 0};
    for(auto x:vec)
    {
        if(tmp.b() == x.f()) tmp = x;
        else
        {
            cout << tmp.pb() << " - " << x.pf() << endl;
            tmp = x;
        }
    }
    if(vec.back().b() != 235959) cout << vec.back().pb() << " - " << "23:59:59" << endl;
}
signed main()
{
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}