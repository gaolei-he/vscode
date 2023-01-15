#include <iostream>
using namespace std;
const int N = 2e6+10;
int a[N];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) a[i] = i;
    for(int i=1, j=n+1;1;i+=2, j++)
    {
        printf("%d", a[i]);
        a[j] = a[i+1];
        if(j-n > n - 1) break;
        else printf(" ");
    }
    return 0;
}
