#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int l = 0, r = nums.size();
        map<int, multiset<int>> ansl, ansr;
        map<int, int> mpl, mpr;
        for(auto x : nums) mpr[x] ++;
        for(auto &[k, v] : mpr) ansr[v].insert(k);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            l ++, r --;
            int cnt = ++ mpl[nums[i]];
            ansl[cnt].insert(nums[i]);
            if(cnt - 1) ansl[cnt - 1].erase(ansl[cnt - 1].find(nums[i]));
            if(ansl[cnt - 1].empty()) ansl.erase(cnt - 1);
            cnt = -- mpr[nums[i]];
            if(cnt) ansr[cnt].insert(nums[i]);
            else mpr.erase(nums[i]);

            ansr[cnt + 1].erase(ansr[cnt + 1].find(nums[i]));
            if(ansr[cnt + 1].empty()) ansr.erase(cnt + 1);
            int v1 = *(ansl.rbegin()->second.begin());
            int v2 = *(ansr.rbegin()->second.begin());
            cerr << v1 << ' ' << v2 << endl;
            if(ansl.rbegin()->first * 2 > l and ansr.rbegin()->first * 2 > r and v1 == v2) return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,2,2,2};
    cout << s.minimumIndex(nums);
}