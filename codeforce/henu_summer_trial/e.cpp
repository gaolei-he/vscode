#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        for (int i = 0;true; i++)
        {
            if(x - (i*(1+i)/2) <= i)
            {
                cout << x - (i*(i+1) / 2) << endl;
                break;
            }
        }
        
    }
    
    
    return 0;
}