#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        int n = nums.size() - 1;
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        for(int i=0;i<=n;i++)
        {
            vector<int> vec(n+1);
            int sm = 0;
            for(int j=i+1;j<=n;j++)
            {
                vec[nums[j]] ++;
                if(vec[nums[j]] == 2) sm += 2;
                else if(vec[nums[j]] > 2) sm ++;
                dp[j] = min(dp[j], dp[i]+sm+k);
            }
        }
        return dp[n];

    }
};
int main()
{

    return 0;
}