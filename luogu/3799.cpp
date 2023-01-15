#include <iostream>
#include <algorithm>
#define N 1000000007
using namespace std;
/*
bool check(long long i, long long j, long long k, long long l)
{
    long long b[] = {i, j, k, l};
    sort(b, b+4);
    if(b[0]!=b[1]&&b[1]!=b[2]&&b[2]!=b[3]) return false;
    if(b[2]==b[3])
        if(b[0]+b[1]==b[2]) return true;
        else return false;
    return false;
}

int main()
{
    long long cnt = 0;
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0;i<n;i++) scanf("%d", &a[i]);
    for(long long i=0;i<n-3;i++)
    for(long long j=i+1;j<n-2;j++)
    for(long long k=j+1;k<n-1;k++)
    {
        for(long long l=k+1;l<n;l++)
        if(check(a[i], a[j], a[k], a[l])) cnt ++;
        if(cnt>N) cnt %= N;
    }
    cout << cnt;
    return 0;
}//tle
*/
long long C(long long n, long long r)
{
    long long ans = 1;
    for(long long i=1;i<=r;i++) ans = ans * (n--) / i;
    return ans;
}
int main()
{
    long long n, cnt = 0;
    cin >> n;
    long long a[n], b[5009] = { 0 };
    for(long long i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
        b[a[i]] ++;
    }
    sort(a, a+n);
    for(long long i=5005;i>=0;i--)
    {
        long long sum = 0;
        if(b[i]>1) 
        {
            for(long long j=i-1;j>=0;j--)
            {
                if(j+j==i)
                {
                    sum += C(b[j], 2);
                    break;
                }
                else if(j<=(i>>1)) break;
                sum += b[j] * b[i-j];
            }
            cnt += sum * C(b[i], 2);
        }
        if(cnt>N) cnt %= N;
    }
    cout << cnt;
    return 0;
}