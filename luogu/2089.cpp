#include <iostream>
int n, cnt = 0;
int a[10000][10], a1[10];
void f(int sum, int times);
using namespace std;
int main()
{
    
    cin >> n;
    /*for(int a=1;a<4;a++)
    for(int b=1;b<4;b++)
    for(int c=1;c<4;c++)
    for(int d=1;d<4;d++)
    for(int e=1;e<4;e++)
    for(int f=1;f<4;f++)
    for(int g=1;g<4;g++)
    for(int h=1;h<4;h++)
    for(int i=1;i<4;i++)
    for(int j=1;j<4;j++)
        if(a+b+c+d+e+f+g+h+i+j==n)
            cnt ++;
    if(cnt)
    {
        cout << cnt << endl;
        for(int a=1;a<4;a++)
        for(int b=1;b<4;b++)
        for(int c=1;c<4;c++)
        for(int d=1;d<4;d++)
        for(int e=1;e<4;e++)
        for(int f=1;f<4;f++)
        for(int g=1;g<4;g++)
        for(int h=1;h<4;h++)
        for(int i=1;i<4;i++)
        for(int j=1;j<4;j++)
            if(a+b+c+d+e+f+g+h+i+j==n)
                printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
    }
    else cout << cnt;
    循环版本*/
    f(0, 0);
    if(cnt)
    {
        cout << cnt << endl;
        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<10;j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    else cout << cnt;
    return 0;
}
void f(int sum, int times)
{
    if(times==10)
    {
        for(int i=0;i<10;i++) a[cnt][i] = a1[i];
        if(sum==n) cnt ++;
    }
    else if(times<10)
    {
        for(int i=1;i<4;i++)
        {
            a1[times] = i;
            f(sum+i, times+1);
        }
    }
}