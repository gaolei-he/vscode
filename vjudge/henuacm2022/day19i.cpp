#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            int t = i % x;
            if(t >= y && t <= z) flag = false;
        }
        if(flag) puts("Can Take off");
        else puts("Cannot Take off");
    }
    
    return 0;
}