#include <iostream>
#include <cmath>
int isPrime(int n);
void f(int a[], int sum, int len, int l);
int n, k, cnt = 0;
using namespace std;
int main()
{
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    f(a, 0, 0, 0);
    cout << cnt;
    return 0;
}

int isPrime(int n)
{
    if(n<=1) return 0;
    if(n==2||n==3) return 1;
    if(n%2==0||n%3==0) return 0;
    int len = sqrt(n);
    for(int i=5;i<=len;i+=6)
        if(n%i==0||n%(i+2)==0) return 0;
    return 1;
}

void f(int a[], int sum, int len, int l)
{
    if(len==k&&isPrime(sum)) cnt ++;
    else
    {
        for(int i=l;i<n;i++)
        {
            sum += a[i];
            f(a, sum, len+1, i+1);
            sum -= a[i];
        }
    }
}