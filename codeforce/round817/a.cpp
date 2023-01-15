#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[] = "Timru";
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char tmp[20];
        scanf("%d %s", &n, tmp);
        sort(tmp, tmp+n);
        if(strcmp(tmp, s) == 0) puts("YES");
        else puts("NO");

    }
    
    return 0;
}