#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5+10;

bool isPrime(ll x)
{
    if(x < 2) return false;
    for(int i=2;i<=x/i;i++)
        if(x % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll x;
        scanf("%lld", &x);
        ll tmp = sqrt(x);
        if (tmp * tmp == x && isPrime(tmp)) puts("YES");
        else puts("NO");
    }
    
    return 0;
}