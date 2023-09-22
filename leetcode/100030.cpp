#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii = pair<int, int>;
    int minimumMoves(vector<vector<int>>& grid) {
        int res = 1e9;
        vector<vector<pii>> vec;
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        auto bfs = [&](int x, int y) {
            vec.push_back(vector<pii>());
            vec.back().push_back({x, y});
            vector<vector<bool>> vis(3, vector<bool>(3));
            vis[x][y] = true;
            queue<pair<int, int>> q;
            q.push({x, y});
            while(q.size())
            {
                cerr << q.size() << endl;
                int tx = q.front().first, ty = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = tx + dx[i], ny = ty + dy[i];
                    if(nx < 0 or nx >= 3 or ny < 0 or ny >= 3 or vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    // cerr << nx << ' ' << ny << endl;
                    if(grid[nx][ny] == 0)
                    {
                        vec.back().push_back({nx, ny});
                    }
                }
            }
            while(-- grid[x][y] != 1) vec.push_back(vec.back());
        };
        for (int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(grid[i][j] > 1) {
                    bfs(i, j);
                }
            }
        }
        int tmp = 0;
        vector<vector<bool>> vis(3, vector<bool>(3));
        function<void(int)> dfs = [&](int cnt) {
            if(cnt == vec.size())
            {
                res = min(tmp, res);
                return;
            }
            int tx = vec[cnt].front().first, ty = vec[cnt].front().second;
            for(auto [x, y] : vec[cnt]) {
                if(tx == x and ty == y) continue;
                else if(vis[x][y]) continue;
                tmp += abs(tx - x) + abs(ty - y);
                vis[x][y] = true;
                dfs(cnt + 1);
                tmp -= abs(tx - x) + abs(ty - y);
                vis[x][y] = false;
            }
        };
        dfs(0);
        return res;
    }
};
int main()
{
    Solution so;
    vector<vector<int>> vec = {{1,1,0},{1,1,1},{1,2,1}};
    so.minimumMoves(vec);
}