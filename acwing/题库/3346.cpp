#include <iostream>
#include <algorithm>
using namespace std;
/*
int main()
{
    int b[7], a[7];
    for(int i=0;i<7;i++)
    {
        scanf("%d", &b[i]);
        a[i] = i;
    }
    do
    {
        
        if(b[a[0]]<=b[a[1]]&&b[a[1]]<=b[a[2]]&&b[a[3]]==b[a[0]]+b[a[1]]&&b[a[4]]==b[a[1]]+b[a[2]]&&b[a[5]]==b[a[0]]+b[a[2]]&&b[a[6]]==b[a[0]]+b[a[1]]+b[a[2]])
        {
            printf("%d %d %d", b[a[0]], b[a[1]], b[a[2]]);
            //printf(" %d %d %d %d", b[a[3]], b[a[4]], b[a[5]], b[a[6]]);
            break;
        }
    } while (next_permutation(a, a+7));
    
    return 0;
}
*/
int main()
{
    int a[7];
    for(int i=0;i<7;i++) scanf("%d", &a[i]);

    sort(a, a+7);
    printf("%d %d %d", a[0], a[1], a[6]-a[0]-a[1]);
    return 0;
}