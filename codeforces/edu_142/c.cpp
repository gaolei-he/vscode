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
const int N = 10+2e5, mod = 1e9 + 7;
int a[N], n;
bool check(int k)
{
    vector<int> nums;
    rep(i, 1, n)
        if(a[i] > k && a[i] <= n - k) nums.push_back(a[i]);
    rep(i, 0, nums.size()-2) if(nums[i] + 1 != nums[i + 1]) return false;
    return true;
}
int solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int l = 0, r = n / 2;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;

    return 0;
}