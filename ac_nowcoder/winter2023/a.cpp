#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
char str[12];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a = 0, b = 0;
        cin >> str + 1;
        int ans = 0;
        rep(i, 1, 10)
        {
            if(i&1 && str[i] == '1') a ++;
            else if(i%2==0 && str[i] == '1') b ++;
            if((10 - i) / 2 + a < b)
            {
                ans = i;
                break;
            }
            else if(i&1 && b + (10-i)/2+1<a)
            {
                ans = i;
                break;
            }
            else if(i%2==0 && b + (10-i)/2<a)
            {
                ans = i;
                break;
            }
        }
        if((a > b || b > a) && ans == 0) ans = 10;
        if(ans) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}