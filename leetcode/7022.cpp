#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int, int> mp;
        for(int i=x;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(mp.empty()) break;
            auto it = mp.lower_bound(nums[i]);
            if(it != mp.end()) res = min(res, abs(nums[i] - it->first));
            if(it != mp.begin())-- it, res = min(res, abs(nums[i] - it->first));
            mp[nums[i + x]] --;
            if(mp[nums[i + x]] == 0) mp.erase(nums[i + x]);
        }
        return res;
    }
};