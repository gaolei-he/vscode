#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

long long f(long long t, long long op)
{
    long long ans = 1;
    while(t)
    {
        t /= 10;
        ans *= 10;
    }
    if(op == 0) return ans;
    else return ans * 10;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a;
        scanf("%lld", &a);
        long long tmp = a;
        tmp = f(tmp, 0);
        printf("%lld\n", a - tmp / 10);

    }
    
    return 0;
}