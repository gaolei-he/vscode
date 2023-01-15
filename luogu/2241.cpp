#include <iostream>
using namespace std;
int n, m;
long long numbers(int len, int wide);
int main()
{
    cin >> n >> m;
    int min = m>n?n:m;
    int max = m>n?m:n;
    long long cnt1 = 0, cnt2 = 0, sum = 0;
    for(int i=1;i<=min;i++)   
    {
        cnt1 += (min-i+1) * (max-i+1);
        for(int j=1;j<=max;j++)
            sum += numbers(i, j);
        
    }
    printf("%lld %lld", cnt1, sum-cnt1);
    return 0;
}

long long numbers(int len, int wide)
{
    int min = m>n?n:m;
    int max = m>n?m:n;
    long long sum = (min-len+1) * (max-wide+1);
    return sum;
}