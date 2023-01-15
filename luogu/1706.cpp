#include <iostream>
#include <algorithm>
int n, a[10], b[10];
using namespace std;

void print()
{
    for(int i=1;i<=n;i++) printf("%5d", a[i]);
    printf("\n");
}

void dfs(int k)
{
    if(k==n)
    {
        print();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            a[k+1] = i;
            b[i] = 1;
            dfs(k+1);
            b[i] = 0;
        }
    }
}

int main()
{

    cin >> n;
    dfs(0);
    return 0;
}