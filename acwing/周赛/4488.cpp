#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x) flag = true;
    }
    if(flag) puts("YES");
    else puts("NO");
    
    return 0;
}