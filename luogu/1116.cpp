#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    while(n)
    {
        for(int i=0;i<n-1;i++)
            if(a[i]>a[i+1])
            {
                swap(a[i], a[i+1]);
                cnt ++;
            }
        n --;
    }
    cout << cnt;
    return 0;
}