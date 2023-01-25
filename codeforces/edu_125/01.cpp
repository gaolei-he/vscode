#include <iostream>
#include <cmath>
using namespace std;
bool ans[51][51];
int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a==0&&b==0) printf("0\n");
        else if(sqrt(a*a+b*b)==floor(sqrt(a*a+b*b))) printf("1\n");
        else printf("2\n");
    }
    return 0;
}