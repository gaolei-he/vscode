#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i=b;;i+=a)
    {
        if((i-d)%c==0&&i>=d)
        {
            cout << i;
            break;
        }
        if(i>1e8)
        {
            cout << -1;
            break;
        }
    }
    return 0;
}