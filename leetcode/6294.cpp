#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> vec;
    vector<int> pr;
    bool stt[100010];
    long long dfs(int st) {
        long long res = pr[st];
        stt[st] = true;
        long long tmp = 0;
        bool flag = true;
        for(auto& i:vec[st])
        {
            if(!stt[i])
            {
                stt[i] = true;
                tmp = max(dfs(i), tmp);
                stt[i] = false;
            }
        }
        
        return tmp + res;
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        if(n == 1) return 0;
        pr = price;
        vec.resize(n);
        for(auto& i:vec) vec.resize(n);
        for(auto& v:edges) vec[v.front()].push_back(v.back()), vec[v.back()].push_back(v.front());
        long long res = 0;
        for(int i=0;i<vec.size();i++)
            if(vec[i].size() == 1) res = max(res, dfs(i)-price[i]);
        return res;
    }
};
int main()
{

    return 0;
}