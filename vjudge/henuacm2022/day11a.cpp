#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;
int ne[N];
char str1[N], str2[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        str1[0] = str2[0] = '$';
        scanf("%s", str2+1);
        scanf("%s", str1+1);
        int length1 = strlen(str1+1), length2 = strlen(str2+1);
        for(int i=2, j=0;i<=length2;i++)
        {
            while(j && str2[i] != str2[j+1]) j = ne[j];
            if(str2[i] == str2[j+1]) j++;
            ne[i] = j;
        }
        int cnt = 0;
        for(int i=1, j=0;i<=length1;i++)
        {
            while(j && str1[i] != str2[j+1]) j = ne[j];
            if(str1[i] == str2[j+1]) j ++;
            if(j == length2)
            {
                cnt ++;
                j = ne[j];
            }
        }
        cout << cnt << endl;
    }
    
}