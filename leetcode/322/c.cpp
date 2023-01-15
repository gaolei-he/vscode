#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        n += 200000;
        int dist[n + 10], h[n + 10];
        int e[n + 10], ne[n + 10], w[n + 10], idx = 0;
        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        memset(w, 0, sizeof(w));
        memset(dist, 0x3f, sizeof(dist));
        function<void(int, int, int)> add = [&](int a, int b, int c) {
            e[idx] = b;
            ne[idx] = h[a];
            w[idx] = c;
            h[a] = idx ++;
        };
        int dis = 0x3f3f3f3f;
        for(auto i:roads)
        {
            add(i[0], i[1], i[2]);
            add(i[1], i[0], i[2]);
            if(i[0] == 1 || i[1] == 1) dis = min(dis, i[2]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
        
        q.push({dis, 1});
        bool st[n + 10];
        dist[1] = dis;
        memset(st, 0, sizeof(st));
        while(q.size())
        {
            auto t = q.top();
            q.pop();
            int ver = t.second, dis = t.first;
            // if(st[ver]) continue;
            for(int i=h[ver];i!=-1;i=ne[i]) {
                int j = e[i];
                if(dist[j] > w[i] || dist[j] > dist[ver]) {
                    // cout << ver << ' ' << j << ' ' << w[i] << endl;
                    dist[j] = min(dist[ver], w[i]);
                    q.push({dist[j], j});
                    
                }
            }
            // st[ver] = true;
        }
        n -= 200000;
        return dist[n];

    }
};
int main()
{

    return 0;
}