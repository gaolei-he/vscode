#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int mod = 1e9+7;
using ar3 = array<int, 3>;
class Solution {
public:
    int lowbit(int x) { return x & (-x);}
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primes;
        vector<int> vec1;
        vector<bool> vis(1010, false);
        for(int i=2;i<=1000;i++) {
            if(!vis[i]) primes.push_back(i);
            for(int j = i + i;j<=1000;j+=i) vis[j] = true;
        }
        for(auto &x : nums) {
            vec1.push_back(x);
            int val = 0;
            for(auto p : primes) {
                if(p * p > x) break;
                val ++;
                while(x % p == 0) x /= p;
            }
            if(x > 1) val ++;
            x = val;
        }
        int n = nums.size();
        vector<vector<pii>> f(n + 1, vector<pii>(26));
        vector<int> lg(n + 1);
        lg[1] = 0, lg[2] = 1;
        for(int i=3;i<=n;i++)
            if(lowbit(i) == i) lg[i] = lg[i - 1] + 1;
            else lg[i] = lg[i - 1];
        for(int i=1;i<=n;i++) f[i][0] = {nums[i - 1], -i};
        int ed = 25;
        for(int j=1;j<=ed;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        
        auto quick_pow = [&](int x, int y) {
            long long res = 1;
            while (y) {
                if(y & 1) res = 1ll * res * x % mod;
                x = 1ll * x * x % mod;
                y >>= 1;
            }
            return res;
        };
        auto query = [&](int l, int r) {
            int s = lg[r - l + 1];
            return max(f[l][s], f[r - (1 << s) + 1][s]);
        };
        int res = 1;
        vector<ar3> vec;
        function<void(int, int)> dfs = [&](int l, int r) {
            auto p = query(l, r);
            int mid = - p.second;
            vec.push_back({nums[mid - 1], vec1[mid - 1], (mid - l + 1) * (r - mid + 1)});
            if(l < mid) dfs(l, mid - 1);
            if(mid < r) dfs(mid + 1, r);
        };
        dfs(1, n);
        sort(vec.begin(), vec.end(), [&](ar3 a, ar3 b) {
            return a[0] > b[0];
        });
        for(auto [t, a, b] : vec) {
            res = 1ll * res * quick_pow(a, min(b, k)) % mod;
            k -= min(b, k);
            if(k == 0) break;
        }
        return res;
    }
};