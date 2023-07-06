#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char str[20];
int main()
{
    printf("%ld\n", clock()/CLOCKS_PER_SEC);
    for (int i = 0; i < 100000000; i++)
    {
        // sprintf(str, "%d", i);
        i += 1;
        i -= 1;
    }
    printf("%ld", clock()/CLOCKS_PER_SEC);
    
}