#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5+10;
char str[N], tmp[N];
int a[26];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> str+1 >> tmp+1;
        memset(a, 0, sizeof(a));
        for(int i=1;str[i];i++) a[str[i]-'a'] ++;
        for(int i=1;tmp[i];i++) a[tmp[i]-'a'] --;
        bool flag = true;
        for(int i=2;tmp[i];i++)
        {
            if(tmp[i-1] > tmp[i])
            {
                flag = false;
                break;
            }
            else if(tmp[i-1] < tmp[i])
            {
                flag = true;
                break;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(!flag && tmp[1]<=i+'a') break;
            else if(flag && tmp[1]<i+'a') break;
            while(a[i]--) putchar(i+'a');
            a[i] = 0;
            
        }
        printf("%s", tmp+1);
        for(int i=0;i<26;i++) while(a[i]--) putchar(i+'a');
        puts("");
    }
    

}