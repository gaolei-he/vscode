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
const int N = 10 + 2e5, mod = 1e9 + 7;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int i;
        for(i=0;i<nums.size();i++) {
            if(nums[i] == k) break;
        }
        map<int, int> mp;
        int t = 0;
        for(int j=i;j<nums.size();j++) {
            if(nums[j] > nums[i]) t ++;
            else if(nums[j] < nums[i]) t --;
            mp[t] ++;
        }
        int res = 0;
        t = 0;
        for(int j=i;j>=0;j--) {
            if(nums[j] > nums[i]) t ++;
            else if(nums[j] < nums[i])t --;
            res += mp[-t];
            res += mp[-t+1];
        }
        return res;
    }
};

void solve()
{
    Solution so = Solution();
    
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