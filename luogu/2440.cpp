#include <iostream>
using namespace std;

bool check(int a[], int k, int n, int mid)
{
    int sum = 0;
    for(int i=0;i<n;i++) sum += a[i] / mid;
    if(sum>=k) return true;
    return false;
}


int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int sum = 0;
    int l = 0, r = 1e8;
    while(l<r)
    {
        int mid = l + r + 1 >> 1;
        if(check(a, k, n, mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l;
    return 0;
}