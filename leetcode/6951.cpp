#include <bits/stdc++.h>
using namespace std;
using ar2 = array<int, 2>;
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<ar2> q;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1)
                    q.push({i,j}), vis[i][j] = true;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        queue<ar2> tmp1;
        function<bool(int, int)> dfs = [&](int x, int y) {
            if(x == n - 1 and y == n - 1) return true;
            bool res = false;
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx < 0 or tx >= n or ty < 0 or ty >= n or vis[tx][ty]) continue;
                tmp1.push({tx, ty});
                vis[tx][ty] = true;
                res |= dfs(tx, ty);
                if(res) return res;
            }
            return res;
        };
        function<void()> bfs = [&]() {
            queue<ar2> tmp;
            while(q.size())
            {
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = x + dx[i], ty = y + dy[i];
                    if(tx < 0 or tx >= n or ty < 0 or ty >= n or grid[tx][ty]) continue;
                    grid[tx][ty] = 1;
                    vis[tx][ty] = true;
                    tmp.push({tx, ty});
                }
                
            }
            q = move(tmp);
        };
        int res = 0;
        while(!vis[0][0] and !vis[n-1][n-1] and dfs(0, 0))
        {
            res ++;
            while(tmp1.size())
            {
                int x = tmp1.front()[0], y = tmp1.front()[1];
                tmp1.pop();
                vis[x][y] = false;
            }
            bfs();
        }
        return res;
    }
};
int main()
{
    Solution so;
    vector<vector<int>> grid = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
    cout << so.maximumSafenessFactor(grid);
}