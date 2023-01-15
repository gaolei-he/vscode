/*
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<50;i++)
        for(int j=i+1;j<50;j++)
            for(int k=j+1;k<50;k++)
            if(n*(i*j+j*k+i*k)==2*i*j*k) printf("%d %d %d\n", i, j, k);
    return 0;
}
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n<=1) cout << -1;
    else printf("%d %d %d", n, n+1, n*(n+1));
    return 0;
}