#include <stdio.h>
int main()
{
    int i = 1;
    int x =0 , y;
    i = (++i) +
     (x=++i);
    printf("%d %d %d", i, x, y);
    return 0;
}