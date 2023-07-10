#include <vector>
using namespace std;
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i=1;i<=n;i++) {
            if(i > 1 and nums1[i-1] >= nums1[i-2]) dp[i][0] = dp[i-1][0] + 1;
            else dp[i][0] = 1;
            if(i > 1 and nums1[i-1] >= nums2[i-2]) dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
            else dp[i][0] = max(dp[i][0], 1);
            if(i > 1 and nums2[i-1] >= nums1[i-2]) dp[i][1] = dp[i-1][0] + 1;
            else dp[i][1] = 1;
            if(i > 1 and nums2[i-1] >= nums2[i-2]) dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
            else dp[i][1] = max(dp[i][1], 1);
        }
        int res = 0;
        for(int i=1;i<=n;i++) res = max(res, max(dp[i][0], dp[i][1]));
        return res;
    }
};