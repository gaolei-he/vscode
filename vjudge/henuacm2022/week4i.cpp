#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    long long n;
    //cin >> n;
    for(long long i=1;i<=10000000000;i++)
    {
        int t = 0, sum = 0;
        ll tmp = i;
        while(tmp)
        {
            t ++;
            sum += tmp % 10;
            tmp /= 10;
        }
        if((t<<1)==sum) printf("%lld, ", i);

    }
    return 0;
}
