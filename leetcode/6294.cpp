#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> vec;
    vector<int> pr;
    long long dfs(int st) {
        long long res = pr[st];
        if(vec[st].size() == 1) return res + pr[vec[st].front()];
        int tmp = 0;

        for(auto& i:vec[st])
            tmp = max(dfs(i), tmp);
        return tmp + res;
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
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