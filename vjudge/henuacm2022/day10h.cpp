#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
int fib[N], s[N];
bool mex[N];
int n, m, p;
void f()
{
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > N) break;
    }
    for(int i=1;i<=n;i++)
    {
        memset(mex, 0, sizeof(mex));
        for(int j=1;fib[j] <= i;j++) mex[s[i-fib[j]]] = 1;
        for(int j = 0;j<=n;j++) if(!mex[j]) {s[i] = j; break;}
    }
}
int main()
{
    n = 1000;
    f();
    while (cin >> m >> n >> p)
    {
        if(!m) break;
        if (s[m] ^ s[n] ^ s[p])
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}