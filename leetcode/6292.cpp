#include <bits/stdc++.h>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n+1);
        for(auto i:res) i.resize(n+1);
        for(auto vec:queries)
        {
            int x1 = vec[0], y1 = vec[1], x2 = vec[2], y2 = vec[3];
            res[x1][y1] ++;
            res[x1][y2+1] --;
            res[x2+1][y1] --;
            res[x2+1][y2+1] ++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int a, b, c;
                if(i-1>=0) a = res[i-1][j];
                else a = 0;
                if(j-1>=0) b = res[i][j-1];
                else b = 0;
                if(i-1 >= 0 && j - 1 >= 0) c = res[i-1][j-1];
                else c = 0;
                res[i][j] = a + b - c;
            }
        res.pop_back();
        for(auto& vec:res) vec.pop_back();
        return res;
    }
};