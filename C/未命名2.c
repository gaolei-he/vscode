#include <stdio.h>
#define MOD 1000000007
long long a[1002][1002] = { 0 };
int main()
{
    a[1][1] = 1, a[2][1] = 1, a[2][2] = 1;
    int i, j, k;
    for(i=3;i<1001;i++){
        for(j=1;j<=i;j++){
            a[i][j] = (a[i-1][j]+a[i-1][j-1])%MOD;
        }
    }
    //printf("%d", a[4][2]);
    int t;
    scanf("%d", &t);
    while(t--){
        int m, n;
        scanf("%d %d", &n, &m);
        printf("%lld\n", a[n-1][m-1]%MOD);
    }
    
    return 0;
}
