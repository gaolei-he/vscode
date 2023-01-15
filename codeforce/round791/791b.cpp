#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
typedef pair<long long, long long> PII;

long long search1(long long *q, long long i)
{
    if(q[i] <= 0) return -1;
    else return q[i];
}
const int N = 2e5;
long long query[N+1];
int main()
{

    long long n, q;
    cin >> n >> q;
    long long a[n+1];
    long long sum = 0;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    
    long long all = -1;

    while (q--)
    {
        long long t;
        scanf("%lld", &t);
        if(t==1)
        {
            long long i, x;
            scanf("%lld %lld", &i, &x);
            long long tmp = search1(query, i);
            if(tmp>=0) sum += x - tmp;
            else sum += x - (all==-1?a[i]:all);
            printf("%lld\n", sum);
            query[i] = x;
        }
        else
        {
            long long x;
            scanf("%lld", &x);
            printf("%lld\n", x*n);
            sum = x * n;
            all = x;
            memset(query, 0, sizeof(query));
            //cout << query[0].second;
        }
    }
    
    return 0;
}