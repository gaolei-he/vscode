#include <iostream>
#include <bits/stdc++.h>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto i:nums) a += i;
        for(auto i:nums)
        {
            int t = i;
            while(t) b += t % 10, t /= 10;
        }
        return abs(a-b);
    }
};
int main()
{

    return 0;
}