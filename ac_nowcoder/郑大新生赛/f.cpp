#include <iostream>
using namespace std;
const int N = 1e3+10;
int a[N];
int xo[N];
int main()
{
    int n;
    cin >> n;
    int tmp = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        tmp ^= a[i];
    }
    if(tmp == 0)
    {
        puts("0");
        return 0;
    }
    tmp ^= a[1];
    for(int i=2;i<=n;i++)
    {
        xo[i] = tmp ^ a[i];
    }
    for(int i=1;i<a[1];i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(xo[j] ^ (a[1] - i) ^ (a[j] + i) == 0)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}