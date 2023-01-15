#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 20;
char str[N+1][N+1];
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    if(gcd(a, b) == 1 && !(a==1&&b==1)) puts("Yes");
    else puts("No");
    return 0;
}

