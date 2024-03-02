#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        long long res = -1, cnt = 0;
        int n = mat.size(), m = mat[0].size();
        unordered_map<long long, int> mp;

        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        auto isPrime = [&](long long x) {
            for (long long i = 2; i <= x / i; i ++)
                if (x % i == 0) 
                    return false;
            return true;
        };
        auto calc = [&](int x, int y) {
            for (int i = 0; i < 8; i++)
            {
                int vx = x, vy = y;
                string s;
                while(vx >=0 and vx < n and vy >= 0 and vy < m) {
                    s.push_back(mat[vx][vy] + '0');
                    vx += dx[i], vy += dy[i];
                    if(s.size() > 1 and isPrime(stoll(s))) mp[stoll(s)] += 1;
                }
            }
        };

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                calc(i, j);
            }
        }
        
        for(auto [k, v] : mp) {
            if(v > cnt) {
                cnt = v;
                res = k;
            } else if(v == cnt) {
                res = max(k, res);
            }
        }

        return (int)res;
    }
};