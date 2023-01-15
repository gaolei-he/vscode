#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int cnt = 0;
    while(t--)
    {
        cnt ++;
        cout << "Case " << cnt << ": ";
        int n, k;
        cin >> n >> k;
        if(k == 1)
        {
            if(n&1) puts("first");
            else puts("second");
        }
        else
        {
            if(n <= k) puts("first");
            else puts("second");
        }
    }
    return 0;
}