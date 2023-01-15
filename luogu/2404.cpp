#include <iostream>
using namespace std;
int a[10], n;
void f(int cnt, int k, int sum)
{
    
    if(sum==n&&cnt>2)
    {
        cout << a[1];
        for(int i=2;i<cnt;i++) printf("+%d", a[i]);
        puts("");
        return;
    }
    else if(sum>=n) return;
    for(int i=k;i<=n;i++)
    {
        a[cnt] = i;
        sum += i;
        f(cnt+1, i, sum);
        sum -= i;
        a[cnt] = 0;
    }
}

int main()
{
    cin >> n;
    
        f(1, 1, 0);
    
    return 0;
}