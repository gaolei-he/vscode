#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[12], str2[12], tmp[12];
    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str1));
    int cnt = 0;
    while(1)
    {
        cnt ++;
        scanf("%s", tmp);
        if(tmp[0]=='.') break;
        else if(cnt==2) strcpy(str1, tmp);
        else if(cnt==14) strcpy(str2, tmp);
        //else if(tmp[0]=='.') break;
    }
    if(str1[0]&&str2[0]) printf("%s and %s are inviting you to dinner...", str1, str2);
    else if(str1[0]) printf("%s is the only one for you...", str1);
    else printf("Momo... No one is for you ...");
    return 0;
}