#include <iostream>
using namespace std;

const int N = 5e3+10;
int a[N], n, p, h, m;

bool check(int l, int r)
{
    int tmp = min(a[l], a[r]);
    for(int i=l+1;i<r;i++) if(a[i]>=tmp) return false;
    return true;
}

int main()
{
    cin >> n >> p >> h >> m;
    for(int i=1;i<=n;i++) a[i] = h;
    
    int num1, num2;
    while(m--)
    {
        scanf("%d %d", &num1, &num2);
        if(num1>num2) swap(num1, num2);
        if(check(num1, num2)) continue;
        for(int i=num1+1;i<num2;i++) a[i] --;
    }
    for(int i=1;i<=n;i++) printf("%d\n", a[i]);
    return 0;
}