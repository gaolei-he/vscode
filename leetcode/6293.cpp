#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, tmp = 0;
        int i = 0, j = 0;
        map<int, int> mp;
        for(;i<nums.size();i++)
        {
            if(i) mp[nums[i-1]] --;
            int t1 = 0;
            if(mp.count(nums[i-1]))t1 = mp[nums[i-1]];
            if(i && t1)
                tmp -= (t1+1)*t1/2 - (t1)*(t1-1)/2;
            while(tmp < k && j<nums.size())
            {
                int t = nums[j];
                mp[t] ++;
                int t1 = mp[t];
                if(t1 > 1) tmp += t1 * (t1-1) / 2 - (t1-1) * (t1-2) / 2;
                if(tmp >= k) break;
                j++;
                cerr << tmp << endl;
            }
            if(tmp >= k) res += nums.size()-1-j;
        }
        return res;
    }
};
int main()
{
    Solution so;
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(1);
    }
    so.countGood(a, 10);
    
    return 0;
}