#include <iostream>
#include <algorithm>

using namespace std;

struct A
{
    int l, r;
};

bool cmp(A a, A b)
{
    if(a.l==b.l) return a.r%7 < b.r%7;
    else return a.l < b.l;
}

int main()
{
    int n;
    cin >> n;
    A a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i].l);
    for(int i=0;i<n;i++) scanf("%d", &a[i].r);
    sort(a, a+n, cmp);
    for(int i=0;i<n;i++) printf("%d ", a[i].r);
    return 0;
}