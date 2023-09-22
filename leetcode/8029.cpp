#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> vis(101);
        for(auto &vec : nums) {
            int l = vec.front(), r = vec.back();
            for(int i = l; i <= r; i ++) vis[i] = true;
        }
        int res = 0;
        for(auto x : vis) if(x) res ++;
        return res;
    }
};