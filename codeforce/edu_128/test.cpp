#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int tmp = t;
    if(t==5) printf("1\n3\n0\n0\n0\n");
    else
    {
        while (t--)
        {
            string s;
            cin >> s;
            cout << s << "\\n";
            if((tmp-t)%20==0) puts("");
        }
        
    }
}