#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int t = i;
        while(t)
        {
            if(t%10==k) ans ++;
            t /= 10;
        }
    }
    cout << ans << endl;

    return 0;
}