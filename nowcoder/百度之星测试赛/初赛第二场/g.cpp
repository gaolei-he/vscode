#include <iostream>
using namespace std;
int main()
{
    int a[100][100];
    for(int i=1;i<=50;i++) a[1][i] = a[i][1] = 1;
    for(int i=2;i<=100000;i++)
    {
        for(int j=2;j<=100000;j++)
        {
            int tmp = 0;
            
        }
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++) cout << a[i][j] << ' ';
        puts("");
    }
    return 0;
}