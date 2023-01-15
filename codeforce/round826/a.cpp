#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        if(a.back() == b.back())
        {
            if(a.back() == 'S')
            {
                if(a.size() > b.size()) puts("<");
                else if(a.size() == b.size()) puts("=");
                else puts(">");
            }
            else if(a.back() == 'L')
            {
                if(a.size() > b.size()) puts(">");
                else if(a.size() == b.size()) puts("=");
                else puts("<");
            }
            else puts("=");
        }
        else if(a.back() == 'L') puts(">");
        else if(a.back() == 'M')
        {
            if(b.back() == 'L') puts("<");
            else puts(">");
        }
        else puts("<");
    }
    
    return 0;
}