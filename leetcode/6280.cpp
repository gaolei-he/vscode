#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int N = 1e6+10;
    

    vector<int> closestPrimes(int left, int right) {
        bool st[N];
        memset(st, 1, sizeof(st));
        for(int i=2;i<N;i++) 
            for(int j=i+i;j<N;j+=i) st[j] = 0;
        st[1] = 0;
        cerr << st[13] << endl;
        int a = 0, b = 0;
        int last = 0;
        for(;left <= right;left ++) {
            if(!st[left]) continue;
            if(a == 0) a = left;
            else if(b == 0) b = left;
            else if(b - a > left - last) a = last, b = left;
            last = left;
        }
        if(a == 0 || b == 0) return {-1, -1};
        return {a, b};
    }
};
int main()
{
    Solution so = Solution();
    so.closestPrimes(1, 1);
    return 0;
}