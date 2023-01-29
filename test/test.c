#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long a = 0x00003f3f3f3f0000;
    printf("%lln\n", &a);
    printf("%lln", (&a+1));
    return 0;
}