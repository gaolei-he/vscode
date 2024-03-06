#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> res, tmp;
        res.emplace_back(nums[0]);
        tmp.emplace_back(nums[1]);
        for(int i=2;i<nums.size();++i) {
            if(res.back() > tmp.back()) {
                res.emplace_back(nums[i]);
            } else {
                tmp.emplace_back(nums[i]);
            }
        }
        for(auto x : tmp) {
            res.emplace_back(x);
        }
        return res;
    }
};