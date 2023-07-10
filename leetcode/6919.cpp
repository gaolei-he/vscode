#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> tr;
    int n;
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int c) {
        cerr << "#" << x << ' ' << c << endl;
        for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
    }
    int sum(int x) {
        int res = 0;
        for(int i=x;i;i-=lowbit(i)) res += tr[i];
        return res;
    }
    bool checkArray(vector<int>& nums, int k) {
        tr.resize(nums.size() * 10, 0);
        n = nums.size();
        for(int i=1;i<=n;i++) {
            int val = sum(i);
            if(val > nums[i - 1]) return false;
            else if(val == nums[i-1]) continue;
            else if(i + k > n + 1) return false;
            add(i, nums[i-1] - val);
            add(i + k, val - nums[i-1]);
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 2, 3, 1, 1, 0};
    s.checkArray(nums, 3);
    return 0;
}