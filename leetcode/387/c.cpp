#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int x = grid.size() / 2;
        int ans = 1'000'000'000;
        for (int v1 = 0; v1 <= 2; v1++) {
            for (int v2 = 0; v2 <= 2; v2++) {
                if (v1 == v2) {
                    continue;
                }
                int cnt1 = 0, cnt2 = 0;
                for (int i = 0; i < grid.size(); ++i) {
                    for (int j = 0; j < grid.size(); ++j) {
                        if (i == j and i <= x or j == x and i >= x or
                            i + j == x * 2 and i <= x) {
                            if (grid[i][j] != v1) {
                                cnt1 += 1;
                            }
                        } else {
                            if (grid[i][j] != v2) {
                                cnt2 += 1;
                            }
                        }
                    }
                }
                ans = std::min(ans, cnt1 + cnt2);
            }
        }
        return ans;
    }
};