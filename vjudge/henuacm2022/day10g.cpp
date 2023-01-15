#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while(1)
    {
        cin >> n >> m;
        if(!n) break;
        if(n&1 && m&1) puts("What a pity!");
        else puts("Wonderful!");
    }
    return 0;
}