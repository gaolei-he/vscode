#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[i].size();++j) {
                if(i) {
                    grid[i][j] += grid[i-1][j];
                } 
                if(j) {
                    grid[i][j] += grid[i][j-1];
                }
                if(i and j) {
                    grid[i][j] -= grid[i-1][j-1];
                }
                if(grid[i][j] <= k) {
                    res += 1;
                }
            }
        }
        return res;

    }
};