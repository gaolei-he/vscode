#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double l = 0, r = x;
        while(r-l>1e-6)
        {
            double mid = (l+r) / 2;
            
            if(mid*mid>=x) r = mid;
            else l = mid;
        }
        l += 0.00001;
        return (int) l;
    }
};
int main()
{
    int x;
    cin >> x;
    Solution s;
    cout << s.mySqrt(x);
    return 0;
}