#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        map<int, int> mp1, mp2;
        for(auto x : nums) mp1[x] ++;
        long long res = 0;
        for(auto x : nums)
        {
            mp1[x] --;
            if(mp1[x] == 0) mp1.erase(x);
            if(mp1.size() and mp2.size()) res = max(res, (mp2.rbegin()->first - x) * 1ll * (mp1.rbegin()->first));
            mp2[x] ++;
        }
        return res;
    }
};