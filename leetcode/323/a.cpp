#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int k = 0; k < m; k++)
        {
            int ans = 0;
        
            for (int i = 0; i < m; i++)
            {
                int pos = -1, mx = 0;
                for (int j = 0; j < n; j++)
                    if(grid[i][j] > mx) mx = grid[i][j], pos = j;
                grid[i][pos] = 0;
                ans = max(ans, mx);
                
            }
            res += ans;
        }
        return res;
        
    }
};
int main()
{

    return 0;
}