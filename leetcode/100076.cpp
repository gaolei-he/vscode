#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    using pli = pair<long long, int>;
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sm = 0;
        for(auto x : nums) sm += x;
        int tmp = target / sm * nums.size(), res = 1e9 + 10;
        target %= sm;
        vector<long long> s(nums.size() * 2 + 1, 0);
        for(int i=1;i<=nums.size();i++) s[i] = s[i - 1] + nums[i - 1];
        for(int i=1;i<=nums.size();i++) s[i + nums.size()] = s[i + nums.size() - 1] + nums[i - 1];
        set<pli> st;
        for(int i=1;i<=nums.size()*2;i++) st.insert({s[i], i});
        for(int i=1;i<=nums.size();i++)
        {
            // st.erase({s[i], i});
            auto it = st.lower_bound({s[i-1] + target, 0});
            if(it != st.end() and it->first == s[i - 1] + target) res = min(res, it->second - i + 1);
            st.erase({s[i], i});
        }
        if(target == 0) return tmp;
        else if(res > 1e9+3) return -1;
        return res + tmp;
    }
};