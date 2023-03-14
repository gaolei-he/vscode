#include <stdio.h>
int main()
{
    unsigned int a = 0b01111111111111111111111111111111;
    float v = -0.421875;
    int* p = &v;
    printf("%032b", *p);
    return 0;
}
