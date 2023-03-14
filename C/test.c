#include <stdio.h>
int main()
{
    unsigned int a = 0b01111111011111111111111111111111;
    float* v = &a;
    
    printf("%f", *v);
    return 0;
}
