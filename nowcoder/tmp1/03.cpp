#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ret = 1;
        while(n>0)
        {
            n -= ceil(n*1.0/2);
            ret *= -1;
        }
        if(n==0)
        {
            if(ret==1) cout << "YES\n";
            else cout << "NO\n";
        }
        
    }
    
    return 0;
}