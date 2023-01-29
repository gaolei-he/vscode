#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int k=j+1;k<=n;k++)
    {
        if((i^j^k)==0&&i+j>k) cnt ++;
    }
    cout << cnt;
    return 0;
}