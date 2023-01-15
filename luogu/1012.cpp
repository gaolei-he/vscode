#include <iostream>
#include <algorithm>
bool cmp(int a, int b)
{
    int a1[11], b1[11];
    int cnt1 = 0, cnt2 = 0;
    while(a)
    {
        a1[cnt1++] = a % 10;
        a /= 10;
    }
    while(b)
    {
        b1[cnt2++] = b % 10;
        b /= 10;
    }
    int cnt3 = cnt1 - 1, cnt4 = cnt2 - 1;
    while(cnt1&&cnt2)
    {
        if(a1[--cnt1]==b1[--cnt2]) continue;
        else return a1[cnt1] > b1[cnt2];
    }
    if(cnt1) return a1[cnt1-1] > a1[cnt3];
    else return b1[cnt2-1] < b1[cnt4]; 

}
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n, cmp);
    for(int i=0;i<n;i++) printf("%d",a[i]);

}