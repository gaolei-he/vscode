#include <iostream>
using namespace std;
const int N = 2e5+10;
int a[N], s[N];
int main()
{
    int n;

    cin >> n;
    long long num = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        num += a[i];
        s[i] = num;
    }
    long long max = -2e9;
    for(int i=1;i<n;i++)
        for(int j=i;j<=n;j++)
            max = (s[j]-s[i-1]>max)?s[j]-s[i-1] : max;
    cout << max;
    return 0;
}