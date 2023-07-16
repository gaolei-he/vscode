#include <vector>
#include <iostream>
#include <array>
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        array<int, 401000> s;
        s.fill(0);
        for(auto x:nums)
        {
            x += 101000;
            s[x-k] ++;
            s[x+k+1] --;
        }
        for(int i = 1; i < s.size(); i ++) s[i] += s[i-1];
        int res = 0;
        for(int i = 1; i < s.size(); i ++) res = max(res, s[i]);
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {706,702,653,859,929,496,572,450,962,445,296,4,787,888,747,619,757,855,827,966,238,990,525,728,861,536,204,344,5,530,370,591,858,60,393,150,826,283,700,278,957,395,956,889,336,740,902,606,851,122,402,185,396,734,329};
    int k = 989;
    cout << s.maximumBeauty(nums, k);
}