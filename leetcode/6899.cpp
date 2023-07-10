#include <vector>
#include <cmath>
#include <queue>
using namespace std;
class Solution {
public:
    int spfa(vector<vector<int>>& g) {
        vector<int> dist(g.size(), 0x3f3f3f3f);
        dist[1] = 0;
        queue<int> q;
        int n = g.size() - 1;
        q.push(1);
        vector<bool> st(g.size(), false);
        st[1] = true;
        while(q.size())
        {
            int t = q.front();
            q.pop();
            st[t] = false;
            for(auto v : g[t])
            {
                if(dist[v] > dist[t] - 1)
                {
                    dist[v] = dist[t] - 1;
                    if(!st[v])
                    {
                        q.push(v);
                        st[v] = true;
                    }
                }
            }
        }
        return dist[n] == 0x3f3f3f3f ? -1 : -dist[n];

    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> g(n+1);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(abs(nums[i] - nums[j]) <= target)
                    g[i+1].push_back(j+1);
        return spfa(g);
    }
};