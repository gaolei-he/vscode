#include <stdio.h>
main()
{
    int count = 0;
    int n = 2000000000;
    for(int i=1;i<n;i*=2){
        for(int j=0;j<i;j++) {
            count += 1;
        }
    }
    printf("%d\n", count);
}