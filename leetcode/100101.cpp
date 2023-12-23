#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        map<int, int> mp;
        map<int, int> dic;
        for(int i = 0; i < nums.size(); i ++) dic[nums[i]] = i;
        for(int i=indexDifference; i < nums.size(); i++) mp[nums[i]] ++;
        for(int i = 0; mp.size(); i++, indexDifference ++)
        {
            if (abs(nums[i] - mp.begin() -> first) >= valueDifference)
                return {i, dic[mp.begin() -> first]};
            else if (abs(nums[i] - mp.rbegin() -> first) >= valueDifference)
                return {i, dic[mp.rbegin() -> first]};
            mp[nums[indexDifference]] --;
            if (mp[nums[indexDifference]] == 0) mp.erase(nums[indexDifference]);
        }
        return {-1, -1};

    }
};