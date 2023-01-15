#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l0 = 0, l1 = 0;
        for(auto i:s) if(i == '1') l1 ++; else l0 ++;
        if(l0 != l1 && l0 && l1) cout << min(l0, l1) << endl;
        else if(l0 == l1 && l0 > 1) cout << l0 - 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}