#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
vector<PII> a[1010];
const int N = 310;
bool tu[N][N], af[N][N];
int main()
{
    int res = 1;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        a[t].push_back({x, y});
    }
    for (int i = 0; i < 1010; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            af[a[i][j].first][a[i][j].second] = true;
            for (int k = 0; k < 4; k++)
            {
                int x = a[i][j].first + dx[k], y = a[i][j].second + dy[k];
                if(x >= 0 && x <= 300 && y >= 0 && y <= 300) af[x][y] = true;
            }
            
        }
        
    }

    queue<PII> query;
    query.push({0, 0});
    for (int i = 0; i < a[0].size(); i++)
        {
            tu[a[0][i].first][a[0][i].second] = true;
            for (int k = 0; k < 4; k++)
            {
                int x = a[0][i].first + dx[k], y = a[0][i].second + dy[k];
                if(x >= 0 && x <= 300 && y >= 0 && y <= 300) tu[x][y] = true;
            }
            
        }
    af[0][0] = tu[0][0] = true;
    for (int t = 0; t < 1010; t++)
    {
        for (int i = 0; i < a[t+1].size(); i++)
        {
            tu[a[t+1][i].first][a[t+1][i].second] = true;
            for (int k = 0; k < 4; k++)
            {
                int x = a[t+1][i].first + dx[k], y = a[t+1][i].second + dy[k];
                if(x >= 0 && y >= 0) tu[x][y] = true;
            }
            
        }
        auto tmp_query = query;
        while(!query.empty()) query.pop();
        while (!tmp_query.empty())
        {
            auto tmp = tmp_query.front();
            tmp_query.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = tmp.first + dx[i], y = tmp.second + dy[i];
                if(x >= 0 && y >= 0 && tu[x][y] == false)
                {
                    tu[x][y] = true;
                    if(af[x][y] == false)
                    {
                        cout << t + 1 << endl;
                        res = 0;
                        //cout << x << y;
                        return 0;
                    }
                    query.push({x, y});
                }
            }
            
            
        }
        
        
    }
    if(res) cout << -1;
    
    
    return 0;
}