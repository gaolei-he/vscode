#include <iostream>
using namespace std;
int n, r;
void f(int a[], int b[], int l, int cnt)
{
    if(cnt==r)
    {
        for(int i=0;i<r;i++) printf("%3d", b[i]);
        printf("\n");
        return;
    }
    for(int i=l;i<n;i++)
    {
        b[cnt] = a[i];

        f(a, b, i+1, cnt+1);
    }
}

int main()
{
    
    cin >> n >> r;
    int a[n], b[r];
    for(int i=0;i<n;i++) a[i] = i + 1;
    f(a, b, 0, 0);
    return 0;
}