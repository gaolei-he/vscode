#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotInteger(int n) {
        vector<int> a(1100);
        auto f = [](int k) {
            int res = 0;
            while(k) res += k % 10, k /= 10;
            return res;
        };
        for(int i=1;i<=1000;i++) {
            a[i] = a[i-1] + f(i);
        }
        for(int i=1;i<=n;i++) {
            if(a[i] - a[0] == a[n] - a[i-1]) return i;
        }
        return -1;
    }
};
int main()
{
    Solution so = Solution();
    cout << so.pivotInteger(8);
    return 0;
}