#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct A
{
    long long id, time, total;
};

bool cmp(A s1, A s2)
{
    if(s1.time==s2.time) return s1.id < s2.id;
    return s1.time < s2.time;
}

int main()
{
    long long n;
    cin >> n;
    A a[n];
    long long tmp = 0;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld", &a[i].time);
        a[i].id = i + 1;
    }
    sort(a, a+n, cmp);
    long long sum = 0;
    for(long long i=0;i<n;i++)
    {
        printf("%lld", a[i].id);
        a[i].total = tmp;
        sum += tmp;
        tmp += a[i].time;
        if(i==n-1) printf("\n");
        else printf(" ");
        
    }
    printf("%.2f", sum*1.0/n);
    return 0;
}