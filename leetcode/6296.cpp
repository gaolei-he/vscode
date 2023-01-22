#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternateDigitSum(int n) {
        stack<int> stk;
        while(n) stk.push(n % 10), n /= 10;
        int res = 0, op = -1;
        while(stk.size())
        {
            op *= -1;
            res += stk.top() * op;
            stk.pop();
        }
        return res;
    }
};
int main()
{

    return 0;
}