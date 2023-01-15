#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int res = 0;
        queue<long long> q;
        for(auto i:s) q.push((long long)(i-'0'));
        while(q.size())
        {
            long long val = 0;
            while(q.size())
            {
                long long t = q.front();
                if(val * 10 + t > (long long)k) break;
                val = val * 10 + t;
                q.pop();
            }
            if(val) res ++;
            else return -1;
        }
        return res;
    }
};
int main()
{

    return 0;
}