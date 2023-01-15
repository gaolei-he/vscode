#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(auto i:nums) pq.push(i);
        long long res = 0;
        while(k --)
        {
            int t = pq.top();
            pq.pop();
            res += t;
            if(t%3) t = t / 3 + 1;
            else t /= 3;
            pq.push(t);
        }
        return res;
    }
};