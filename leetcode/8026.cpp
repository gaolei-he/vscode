#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prev_ele(auto &p, int x, int y) {
        if (y != 0) return p[x][y-1];
        else if(x != 0) return p[x-1][p[0].size()-1];
        return 1;
    }
    int next_ele(auto &p, int x, int y) {
        if (y != p[0].size()-1) return p[x][y + 1];
        else if (x != p.size() - 1) return p[x + 1][0];
        return 1;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        auto p1 = grid, p2 = grid;
        for(int i=0; i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                p1[i][j] = prev_ele(p1, i, j) * (grid[i][j] % 12345) % 12345;
        for(int i=grid.size()-1;i>=0;i--)
            for(int j=grid[i].size()-1;j>=0;j--)
                p2[i][j] = next_ele(p2, i, j) * (grid[i][j] % 12345) % 12345;
        auto p = grid;
        for(int i=0; i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                p[i][j] = next_ele(p2, i, j) * prev_ele(p1, i, j) % 12345;
        return p;
    }
};