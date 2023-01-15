#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[110];
    char* p;
    scanf("%s", str);
    int ans = 1;
    while(1)
    {
        if(p = strstr(str, "1010"))
        {
            *p = '0';
            *(p+1) = '1';
            *(p+2) = '0';
            *(p+3) = '1';
        }
        else if(p = strstr(str, "100"))
        {
            *p = '0';
            *(p+1) = '1';
            *(p+2) = '1';
        }
        else if(p = strstr(str, "110"))
        {
            *p = '0';
            *(p+1) = '0';
            *(p+2) = '1';
        }
        else if(p = strstr(str, "10"))
        {
            *p = '0';
            *(p+1) = '1';
        }
        
        
        
        
        if(p==NULL) break;
        ans *= -1;
    }
    if(ans==-1) printf("Alice");
    else printf("Bob");
    return 0;
}

2 > 1
6 > 1
4 > 3
10 > 5