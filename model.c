#include <stdio.h>
const int n = 10;
int a[n];
int main()
{
    int n;

    int a[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    
    return 0;
}