#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
char str1[N], str2[N];
int ne[N];
int main()
{
    while(1)
    {
        scanf("%s", str1+1);
        if(str1[1] == '#') break;
        scanf("%s", str2+1);
        int cnt = 0;
        int length1 = strlen(str1+1), length2 = strlen(str2+1);
        for(int i=2, j=0;i<=length2;i++)
        {
            while(j && str2[j+1] != str2[i]) j = ne[j];
            if(str2[j+1] == str2[i]) j ++;
            ne[i] = j;
        }
        int last = -1e5+10;
        for(int i=1, j=0;i<=length1;i++)
        {
            while(j && str1[i] != str2[j+1]) j = ne[j];
            if(str1[i] == str2[j+1]) j ++;
            if(j == length2)
            {
                if(i - last >= length2)
                {
                    cnt ++;
                    last = i;
                }
                j = ne[j];
                
            }
        }
        cout << cnt << endl;
    }
    return 0;
}