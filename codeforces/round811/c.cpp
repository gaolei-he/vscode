#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        scanf("%d", &s);
        string ans = "";
        for(int i=9;i>0;i--) 
        {
            if(!s) break;
            else ans = (char)(min(s, i) + '0') + ans;
            s -= min(s, i);
        }
        cout << ans << endl;
    }
    
    return 0;
}