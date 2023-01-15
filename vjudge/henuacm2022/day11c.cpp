#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e6+10;
int ne[N];
char str[N];
int main()
{
    while(scanf("%s", str+1) != EOF)
    {
        if(str[1] == '.') break;
        int length1 = strlen(str+1);
        for(int i=2,j=0;i<=length1;i++)
        {
            while(j && str[i]!=str[j+1]) j = ne[j];
            if(str[i] == str[j+1]) j ++;
            ne[i] = j;
        }
        int ans = 0;
        int i;

        for(i=length1;;i--) if(ne[i-1]+1!=ne[i] || !ne[i-1]) break;
        
        if((length1-i+1) % (i-1) == 0) printf("%d\n", length1 / (i-1));
        else printf("1\n");
    }
    return 0;
}