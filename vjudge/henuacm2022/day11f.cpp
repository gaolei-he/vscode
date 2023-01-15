#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+10;
char str1[N], str2[N];
int ne[N];
int main()
{
    while(scanf("%s%s", str1+1, str2+1)!=EOF)
    {
        int length1 = strlen(str1+1), length2 = strlen(str2+1);
        memcpy(str1+1+length1, str1+1, length1*sizeof(char));
        for(int i=2, j=0;i<=length2;i++)
        {
            while(j && str2[j+1] != str2[i]) j = ne[j];
            if(str2[j+1] == str2[i]) j ++;
            ne[i] = j;
        }
        bool flag = false;
        for(int i=1, j=0;i<=length1*2;i++)
        {
            while(j && str2[j+1] != str1[i]) j = ne[j];
            if(str2[j+1] == str1[i]) j ++;
            if(j == length2)
            {
                flag = true;
                break;
            }
        }
        if(flag) puts("yes");
        else puts("no");
    }
    return 0;
}