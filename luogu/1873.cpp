#include <iostream>
using namespace std;
int n, m;
const int N = 1e6+10;
int a[N];

bool check(int mid)
{
    long long sum = 0;
    for(int i=0;i<n;i++) if(a[i]>mid) sum += a[i] - mid;
    if(sum>=m) return true;
    else return false;

}

int main()
{

    cin >> n >> m;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    long long l = 1, r = 2e9;
    while(l<r)
    {
        long long mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}