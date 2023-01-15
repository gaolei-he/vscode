#include <cstring>
#include <iostream>
#include <cstdlib>
int ret = 1;
int f(char* i, char* j, char* k);
char ans[1000][5];
using namespace std;
int check(int a, int b, int c)
{
    int arr[10] = { 0 };
    while(a)
    {
        arr[a%10] = 1;
        a /= 10;
    }
    while(b)
    {
        arr[b%10] = 1;
        b /= 10;
    }
    while(c)
    {
        arr[c%10] = 1;
        c /= 10;
    }
    for(int i=1;i<10;i++)
        if(!arr[i]) return 0;
    return 1;
}
int main()
{
    /*int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a, b, c, cnt = 0;
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    for(int k=0;k<9;k++)
    {
        if(i==j||i==k||j==k);
        else sprintf(ans[cnt++], "%d", arr[i]*100+arr[j]*10+arr[k]);
    }
    cin >> a >> b >> c;
    for(int i=0;i<cnt-2;i++)
    for(int j=i+1;j<cnt-1;j++)
    for(int k=j+1;k<cnt;k++)
    {
        if(atoi(ans[i])*1.0/a==atoi(ans[j])*1.0/b&&atoi(ans[i])*1.0/a==atoi(ans[k])*1.0/c)
        {
            if(f(ans[i], ans[j], ans[k]))
            {
                printf("%s %s %s\n", ans[i], ans[j], ans[k]);
                ret = 0;
            }
                
        }
            
    }
    if(ret) cout << "No!!!";
    */
    int ret = 1;
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=123;i<766;i++)
    {
        int j = i * b / 1.0 / a;
        int k = i * c / 1.0 / a;
        if(j<999&&k<999&&check(i, j, k))
        {
            printf("%d %d %d\n", i, j, k);
            ret = 0;
        }
    }
    if(ret) cout << "No!!!";
//简单版
    return 0;
}

int f(char* i, char* j, char* k)
{
    int a[9] = { 0 };
    for(int t=0;t<3;t++)
    a[*(i+t)-49] = 1;
    for(int t=0;t<3;t++)
    a[*(j+t)-49] = 1;
    for(int t=0;t<3;t++)
    a[*(k+t)-49] = 1;
    for(int t=0;t<9;t++)
        if(!a[t]) return 0;
    return 1;
}