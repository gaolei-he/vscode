#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res = -1;
        set<int> lib;
        for(auto i:nums) lib.insert(i);
        for(auto i:nums)
        {
            int l = 1, tmp = i;
            while(tmp * tmp <= 100000) //1e5
            {
                if(lib.find(tmp * tmp) != lib.end()) tmp *= tmp, l ++;
                else break;
            }
            if(l > 1) res = max(res, l);
        }
        return res;
    }
};
int main()
{

    return 0;
}