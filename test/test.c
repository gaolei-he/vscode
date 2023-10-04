#include <stdio.h>
#include <math.h>
int main()
{
    double y;
    scanf("%lf", &y);
    double x = y * sin(y);
    puts("success");
    return 0;
}
