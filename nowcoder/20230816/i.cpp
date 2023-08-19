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
#define int long long
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
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

int solve1(int n)
{
    vector<unsigned char> vec;
    unsigned char* p = (unsigned char *)&n;
    
    rep(i, 0, 3) vec.push_back(p[i]);
    sort(vec.begin(), vec.end(), less<unsigned char>());
    rep(i, 0, 3) p[i] = vec[i];
    return n;

}
struct E {
    int a[8];
    bool operator<(const E &W) const {
        for (int i = 0; i < 8; i++) {
            if (a[i] < W.a[i]) return true;
        }
        return false;
    }
} e[4];

int solve2(int n) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            e[i].a[j] = n % 2;
            n >>= 1;
        }
    }
    sort(e, e + 4);
    int res = 0;

    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            // cout << e[i].a[j];
            res = res * 2 + e[i].a[j];
        }
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
    int n; cin >> n;
    cout << solve1(n);
    return 0;
}