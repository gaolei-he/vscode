#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> a;
int mypow(int a, int b)
{
    int res = 1;
    while (b--) res*= a;
    return res;
}
bool check(int mid)
{
    int ans = 0;
    int tmp = mid;
    for(auto &i:a) i = 0;
    for (int i = 0; tmp; i++)
    {
        a[i] = tmp % 10;
        tmp /= 10;
    }
    tmp = 1;
    for(int i=0;i<a.size();i++)
    {

        tmp *= mypow(10, i);
        int t = 0;
        for(int j=i+1;j<a.size();j++)
        {
            t *= 10;
            t += a[j];
        }
        int tmp1 = (n / mypow(10, i+1) - t);
        if(tmp1) tmp *= tmp1;

        if(a[i] && mid > mypow(10, i))
        {
            t = 0;
            for(int j=0;j<i;j++)
            {
                t *= 10;
                t += a[i];
            }
            tmp += (mypow(10, i) - t);
        }
        ans += tmp;
    }
    if (ans >= k) return true;
    else return false;
}
signed main()
{
    
    cin >> n >> k;
    int l = 0, r = n;
    int tmp = n;
    while(tmp) {a.push_back(0); tmp /= 10;}
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << check(11);
    cout << l << endl;
    


}