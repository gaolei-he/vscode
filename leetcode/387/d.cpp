#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> res, tmp;
        int n = nums.size();
        tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> tr1, tr2;
        res.emplace_back(nums[0]);
        tr1.insert({nums[0], 0});
        tr2.insert({nums[1], 1});
        tmp.emplace_back(nums[1]);
        for(int i=2;i<nums.size();++i) {
            int c1 = tr1.order_of_key({nums[i], n});
            c1 = tr1.size() - c1;
            int c2 = tr2.order_of_key({nums[i], n});
            c2 = tr2.size() - c2;
            if(c1 > c2) {
                res.emplace_back(nums[i]);
                tr1.insert({nums[i], i});
            } else if(c1 < c2) {
                tmp.emplace_back(nums[i]);
                tr2.insert({nums[i], i});
            } else if(c1 == c2) {
                if(tr2.size() < tr1.size()) {
                    tmp.emplace_back(nums[i]);
                    tr2.insert({nums[i], i});
                } else {
                    res.emplace_back(nums[i]);
                    tr1.insert({nums[i], i});
                }
            }
        }

        for(auto x : tmp) {
            res.emplace_back(x);
        }
        return res;
    }
};